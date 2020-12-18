#include "creategroupwidget.h"
#include "ui_creategroupwidget.h"
#import <app-qt/src/delegates/friendsdelegate.h>
#import <QDebug>
#include "netlib/AppNetwork.h"
#include "app-qt/src/utils.h"

CreateGroupWidget::CreateGroupWidget(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::CreateGroupWidget)
{
    ui->setupUi(this);
    createWidget = new QWidget(this);
    this->resize(400,400);
    createWidget->setMaximumSize(400,400);
    contactsWidget = new QWidget(this);
    contactsWidget->setMaximumSize(400,400);
    this->addWidget(createWidget);
    createWidget->setLayout(ui->CreateGroupLayout);
    this->addWidget(contactsWidget);
    contactsWidget->setLayout(ui->ContactsLayout);
    friendModel = std::make_shared<FriendsModel>();
    friendModel->addCallbacks();

    this->setWindowFlags(Qt::Popup);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    proxy = new FriendModelProxy();
    proxy->setSourceModel(friendModel.get());
    connect(this,&CreateGroupWidget::text_changed,proxy,&FriendModelProxy::search_String_Changed);

    addFriend = new addFriendWidget(parent);
    connect(addFriend,&addFriendWidget::friendAddSignal,this,&CreateGroupWidget::on_addFriend);
    ui->createGroupView->setModel(proxy);
    ui->friendsView->setModel(proxy);
    ui->createGroupView->setItemDelegate(new friendsDelegate);
    ui->friendsView->setItemDelegate(new friendsDelegate);
    ui->createGroupView->setSelectionMode(QAbstractItemView::MultiSelection);
    connect(this,&CreateGroupWidget::addFrinedSignal,friendModel.get(),&FriendsModel::addFriendSlot);
    connect(friendModel.get(),&FriendsModel::updateForNames,this,&CreateGroupWidget::updateOnAddFfriend);
}

CreateGroupWidget::~CreateGroupWidget()
{
    delete ui;
}

void CreateGroupWidget::setWidget(WidgetType type)
{
     this->move(Utils::moveToCenter(this->parentWidget()));
    if(type == WidgetType::CONTACTS)
        setCurrentWidget(contactsWidget);
    else
        setCurrentWidget(createWidget);
}

std::shared_ptr<FriendsModel> CreateGroupWidget::getFriendsModel()
{
    return  friendModel;
}

void CreateGroupWidget::on_pushButton_clicked()
{
    this->close();
}

void CreateGroupWidget::on_closeContactsButton_clicked()
{
    this->close();
}

void CreateGroupWidget::on_SearchEditToCreateGroup_textChanged(const QString &arg1)
{
    emit text_changed(arg1);
}

void CreateGroupWidget::on_SearchLineEditFriends_textChanged(const QString &arg1)
{
    emit text_changed(arg1);
}

void CreateGroupWidget::on_pushButton_2_clicked()
{
    if(!ui->createGroupView->selectionModel()->hasSelection()){
        return;
    }
    else{
        if(ui->lineEdit->text().toStdString() == "")
            return;
        QModelIndexList indexList = ui->createGroupView->selectionModel()->selectedRows();
        inf::ChatRoom item;
        std::vector<int> usrIds;
        for(auto& indexData : indexList){
            usrIds.push_back(indexData.data().value<UserInf>().id);
        }
        int myId = UserModel::instance()->getId();
        usrIds.push_back(myId);
        item.idAdmins.push_back(myId);
        item.idUsers = std::move(usrIds);
        item.name = ui->lineEdit->text().toStdString();
        emit groupCreated(item);
        ui->lineEdit->clear();
        this->close();
        emit closeMenu();
    }
}

void CreateGroupWidget::on_addFriend(const QString &str)
{
    emit addFrinedSignal(str);
}

void CreateGroupWidget::on_addFriendButton_clicked()
{
    addFriend->show();
    addFriend->move(Utils::moveToCenter(this));
}

void CreateGroupWidget::getListFriend()
{
    AppNet::shared()->getListFrnd(UserModel::instance()->getId(),friendModel->getFrinedsCallback());
}

void CreateGroupWidget::updateOnAddFfriend()
{
    ui->friendsView->doItemsLayout();
    ui->createGroupView->doItemsLayout();
}

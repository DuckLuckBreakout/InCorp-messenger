#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "ui/Callbacks/Chat.h"
#include "ui/UserData/UserData.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget) {
    qRegisterMetaType<ChatRoom>("ChatRoom");
    qRegisterMetaType<Message>("Message");

    ui->setupUi(this);
    this->resize(810, 550);
    this->setMinimumSize(810, 550);
    this->setMaximumSize(810, 550);
    this->setWindowTitle("InCorp  - messenger");

    ui->chatList->setWindowFlag(Qt::FramelessWindowHint);
    ui->chatList->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->chatList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->chatList->setSelectionMode(QAbstractItemView::NoSelection);
    ui->chatList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->chatList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    chatModel = std::make_shared<ChatModel>();
    ui->chatList->setModel(chatModel.get());

    chatDelegate = new ChatDelegate(this);
    ui->chatList->setItemDelegate(chatDelegate);

    groupModel = std::make_shared<GroupModel>();
    ui->groupList->setModel(groupModel.get());

    groupDelegate = new GroupDelegate(this);
    ui->groupList->setItemDelegate(groupDelegate);

    connect(groupModel.get(), &GroupModel::chatRoomInfo,
            this, &MainWidget::setChatRoomInfo);
    connect(groupModel.get(), &GroupModel::addNewMessage,
            chatModel.get(), &ChatModel::newMessage);

    connect(groupModel.get(), &GroupModel::updateItems,
            ui->groupList, &GroupListView::doItemsLayout);
    connect(chatModel.get(), &ChatModel::updateItems,
            ui->chatList, &ChatView::doItemsLayout);
}

MainWidget::~MainWidget() {
    delete ui;
}


void MainWidget::wheelEvent(QWheelEvent *event) {
    ui->chatList->doItemsLayout();
}


void MainWidget::afterLogin() {

    ListChats listChats;
    Controller::getInstance()->getListChats(listChats, UserData::getInstance()->userId,
                                            std::make_shared<GetListChatsCallback>(shared_from_this()));

    ui->userName->setText(QString::fromStdString("User: <b>" + UserData::getInstance()->firstName + " "
                                                    + UserData::getInstance()->lastName + "<b>"));
    ui->userRole->setText(QString::fromStdString("Role in company: <b>" + UserData::getInstance()->role + "<b>"));
    this->setWindowTitle(QString::fromStdString("Messenger: " + UserData::getInstance()->company));

    this->show();
}

void MainWidget::on_sendMessageButton_clicked() {
    QString text = ui->messageInput->toPlainText().trimmed();
    if(text == "")
        return;

    long int currentTime;
    currentTime = time(NULL);

    auto userData = UserData::getInstance();
    Message message(userData->currentChatId, text.toStdString(),
                    userData->userId, currentTime, chatModel->rowCount() + 1);

    ui->messageInput->clear();
    chatModel->createMessage(message);
    Controller::getInstance()->sendMessage(message, userData->userId,
                                    std::make_shared<SendMessageCallback>(shared_from_this()));
}

void MainWidget::setChatRoomInfo(const ChatRoom& chatRoom) {
    ui->label_2->setText(QString::fromStdString(std::to_string(chatRoom.usersId.size()) + " members"));
}

void MainWidget::on_groupList_clicked(const QModelIndex &index) {
    ui->label->setText(QString::fromStdString("<b>" + index.model()->data(index).value<GroupView>().chatName + "<b>"));
    GroupView chat = index.model()->data(index).value<GroupView>();
    if (UserData::getInstance()->currentChatId != chat.chatId) {
        chatModel->Clear();
        Controller::getInstance()->getChatRoom(ChatRoom(chat.chatId), UserData::getInstance()->userId,
                                               std::make_shared<GetChatRoomCallback>(shared_from_this()));
        UserData::getInstance()->currentChatId = chat.chatId;

        ChatUpdates chatUpdates(1, 0, 5);
        Controller::getInstance()->getChatMessages(chatUpdates, UserData::getInstance()->userId,
                                                   std::make_shared<GetChatMessagesCallback>(shared_from_this()));
    }
}

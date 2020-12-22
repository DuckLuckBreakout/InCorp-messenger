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

    this->setFocusPolicy(Qt::WheelFocus);
    menuWidget = new MenuWidget(this);

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

    listModel = new QStringListModel(this);

    textView = new TextView();
    QCompleter* completer = new QCompleter(this);

    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->messageInput->setCompleter(completer);
    completer->setModel(listModel);


    connect(groupModel.get(), &GroupModel::chatRoomInfo,
            this, &MainWidget::setChatRoomInfo);
    connect(groupModel.get(), &GroupModel::addNewMessage,
            chatModel.get(), &ChatModel::newMessage);

    connect(groupModel.get(), &GroupModel::updateItems,
            ui->groupList, &GroupListView::doItemsLayout);
    connect(chatModel.get(), &ChatModel::updateItems,
            ui->chatList, &ChatView::doItemsLayout);

    connect(groupModel.get(), &GroupModel::messageChecked,
            chatModel.get(), &ChatModel::checkMessages);

    ui->messageInput->installEventFilter(this);
    textMode = InputMessage;
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
    if (text == "")
        return;

    long int currentTime;
    currentTime = time(NULL);

    auto userData = UserData::getInstance();
    Message message(userData->currentChatId, text.toStdString(),
                    userData->userId, currentTime, chatModel->rowCount() + 1);

    ui->messageInput->clear();

    if (textMode == InputMessage) {
        chatModel->createMessage(message);
        Controller::getInstance()->sendMessage(message, userData->userId,
                                               std::make_shared<SendMessageCallback>(shared_from_this()));

        auto it = std::find_if(groupModel->items.begin(), groupModel->items.end(), [message](GroupView &chat) {
            return chat.chatId == message.chatId;
        });

        MessageView newMessage(message);

        it.base()->lastMessage = newMessage;
        User user(newMessage.ownerId, newMessage.chatId);
        Controller::getInstance()->getUser(user, UserData::getInstance()->userId,
                                           std::make_shared<GetUserForGroupCallback>(groupModel));
    }
    else if (textMode == InputCommand) {
        Controller::getInstance()->sendChatCommand(message, userData->userId);
    }
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


        ChatUpdates chatUpdates(chat.chatId, 0, 5);
        Controller::getInstance()->getChatMessages(chatUpdates, UserData::getInstance()->userId,
                                                   std::make_shared<GetChatMessagesCallback>(shared_from_this()));
    }
}

void MainWidget::on_menuButton_clicked() {
    menuWidget->move(QPoint(geometry().x() + 10,geometry().y() + 60));
    menuWidget->show();
    menuWidget->setFocus();
    menuWidget->raise();
}

void MainWidget::keyPressEvent(QKeyEvent *event) {

    int key=event->key();
    if (key==Qt::Key_F1) {
        QString buff = this->ui->messageInput->toPlainText().trimmed();
        this->ui->messageInput->clear();
        if (textMode == InputMessage) {
            textMode = InputCommand;

            QStringList list;
            for (const auto& item : textView->commands)
                list << QString::fromStdString(item.first);
            listModel->setStringList(list);
            this->ui->messageInput->setPlaceholderText("Command");
            this->ui->messageInput->setStyleSheet("background-color: rgb(201, 213, 240);");
        }
        else {
            textMode = InputMessage;
            listModel->setStringList(QStringList());
            this->ui->messageInput->setPlaceholderText("Text");
            this->ui->messageInput->setStyleSheet("background-color: white;");
        }
        this->ui->messageInput->setText(text);
        text = buff;
    }
}

bool MainWidget::eventFilter(QObject *object, QEvent *event)
{
    if (object == this->ui->messageInput && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_F1) {
            QString buff = this->ui->messageInput->toPlainText().trimmed();
            this->ui->messageInput->clear();
            if (textMode == InputMessage) {
                textMode = InputCommand;

                QStringList list;
                for (const auto& item : textView->commands)
                    list << QString::fromStdString(item.first);
                listModel->setStringList(list);
                this->ui->messageInput->setPlaceholderText("Command");
                this->ui->messageInput->setStyleSheet("background-color: rgb(201, 213, 240);");
            }
            else {
                textMode = InputMessage;
                listModel->setStringList(QStringList());
                this->ui->messageInput->setPlaceholderText("Text");
                this->ui->messageInput->setStyleSheet("background-color: white;");
            }
            this->ui->messageInput->setText(text);
            text = buff;
            return true;
        }
    }
    return false;
}

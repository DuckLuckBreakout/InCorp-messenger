#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "ui/Callbacks/Chat.h"
#include "ui/UserData/UserData.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget) {
    ui->setupUi(this);
    this->resize(800,550);
    this->setMinimumSize(800,550);
    this->setMaximumSize(800,550);
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

    connect(chatModel.get(), SIGNAL(updateItems()),
            ui->chatList, SLOT(doItemsLayout()));
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::after_login() {
    ChatUpdates chatUpdates(1, 0, 5);
    Controller::getInstance()->chatUpdate(chatUpdates, UserData::getInstance()->userId,
                                          std::make_shared<UpdateMessagesCallback>(shared_from_this()));

    this->show();
}

void MainWidget::on_sendMessageButton_clicked() {
    QString text = ui->messageInput->toPlainText().trimmed();
    if(text == "")
        return;

    long int currentTime;
    currentTime = time(NULL);

    auto userData = UserData::getInstance();
    Message message(0,
                    text.toStdString(),
                    userData->userId,
                    currentTime,
                    chatModel->rowCount() + 1);

    ui->messageInput->clear();
    chatModel->createMessage(message);
    Controller::getInstance()->sendMessage(message, userData->userId,
                                    std::make_shared<SendMessageCallback>(shared_from_this()));
}
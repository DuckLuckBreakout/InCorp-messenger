#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "ui/Callbacks/Login.h"
#include "ui/UserData/UserData.h"


LoginWidget::LoginWidget(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::LoginWidget) {
    ui->setupUi(this);
    this->resize(800,550);
    this->setMinimumSize(800,550);
    this->setMaximumSize(800,550);
    this->setWindowTitle("InCorp  - messenger");
}

LoginWidget::~LoginWidget() {
    delete ui;
}

void LoginWidget::on_loginButton_clicked() {
    login(ui->loginInput->text(),ui->passwordInput->text());
}

void LoginWidget::login(const QString &login, const QString &password) {
    qDebug() <<"log";

    auto authInfo = Authorization(login.toStdString(),password.toStdString());
    auto client = Controller::getInstance();
    auto callback = std::make_shared<LoginCallback>(shared_from_this());

    auto userData = UserData::getInstance();
    client->authorization(authInfo, userData->userId, callback);

    ui->loginInput->clear();
    ui->passwordInput->clear();
}

void LoginWidget::showMainWidget() {
    emit openMainWidget();
    this->close();
}

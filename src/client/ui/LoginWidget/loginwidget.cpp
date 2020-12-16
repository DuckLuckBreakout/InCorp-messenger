#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "ui/Callbacks/Login.h"
#include "ui/UserData/UserData.h"


LoginWidget::LoginWidget(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::LoginWidget) {
    ui->setupUi(this);
    this->resize(810, 550);
    this->setMinimumSize(810, 550);
    this->setMaximumSize(810, 550);
    this->setWindowTitle("InCorp  - messenger");
}

LoginWidget::~LoginWidget() {
    delete ui;
}

void LoginWidget::on_loginButton_clicked() {
    login(ui->loginInput->text(),ui->passwordInput->text());
}

void LoginWidget::login(const QString &login, const QString &password) {
    const std::string log = login.toStdString();
    const std::string pass = password.toStdString();
    if ((log != "") && (pass != "")) {
        auto authInfo = Authorization(log, pass);
        auto client = Controller::getInstance();
        auto callback = std::make_shared<LoginCallback>(shared_from_this());

        auto userData = UserData::getInstance();
        client->authorization(authInfo, userData->userId, callback);


        ui->loginInput->clear();
        ui->passwordInput->clear();
        ui->SignInLabel->clear();
    }
}

void LoginWidget::showMainWidget() {
    emit openMainWidget();
    this->close();
}

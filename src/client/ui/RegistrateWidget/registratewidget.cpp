#include "registratewidget.h"
#include "ui_registratewidget.h"
#include "ui/Callbacks/Registrate.h"
#include <QDebug>

RegistrateWidget::RegistrateWidget(QWidget *parent)
        :QFrame(parent),
         ui(new Ui::RegistrateWidget) {
    ui->setupUi(this);
//    this->setLayout(ui->mainLayout);
    this->setFrameShadow(QFrame::Raised);
    this->setMinimumWidth(260);
    this->setWindowFlags(Qt::Popup);
    QPalette Pal(palette());
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

RegistrateWidget::~RegistrateWidget() {
    delete ui;
}

void RegistrateWidget::on_signupButton_clicked() {
    Authorization regInfo;

    regInfo.firstName = ui->firstName->text().toStdString();
    regInfo.lastName = ui->lastName->text().toStdString();
    regInfo.role = ui->role->text().toStdString();
    regInfo.login = ui->login->text().toStdString();
    regInfo.password = ui->password->text().toStdString();

    if ((regInfo.firstName != "") && (regInfo.lastName != "") &&
        (regInfo.role != "") && (regInfo.login != "") && (regInfo.password != "")) {

        Controller::getInstance()->registration(regInfo, UserData::getInstance()->userId,
                                                std::make_shared<RegistrationCallback>(this));

//        std::make_shared<RegistrationCallback>(shared_from_this())
        ui->firstName->clear();
        ui->lastName->clear();
        ui->role->clear();
        ui->login->clear();
        ui->password->clear();
    }
}

void RegistrateWidget::setErrorStatus(const QString &string) {
    this->ui->SignUpLabel->clear();
    this->ui->SignUpLabel->setStyleSheet("color: red;");
    this->ui->SignUpLabel->setText(string);
}

void RegistrateWidget::setSuccessStatus(const QString &string) {
    this->ui->SignUpLabel->clear();
    this->ui->SignUpLabel->setStyleSheet("color: green;");
    this->ui->SignUpLabel->setText(string);
}

void RegistrateWidget::clearStatus() {
    this->ui->SignUpLabel->clear();
}
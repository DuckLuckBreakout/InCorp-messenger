#include "menuwidget.h"
#include "ui_menuwidget.h"
#include <QDebug>

#include "ui/Callbacks/Log.h"

MenuWidget::MenuWidget(QWidget *parent)
    :QFrame(parent),
    ui(new Ui::MenuWidget) {
    ui->setupUi(this);
    this->setLayout(ui->mainLayout);
    this->setFrameShadow(QFrame::Raised);
    this->setMinimumWidth(260);
    this->setWindowFlags(Qt::Popup);
    QPalette Pal(palette());
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    this->setFocusPolicy(Qt::WheelFocus);
    logWidget = new LogWidget(this);

}

MenuWidget::~MenuWidget() {
    delete ui;
}

void MenuWidget::on_getLogButton_clicked() {
    logWidget->move(QPoint(geometry().x() + 400,geometry().y() - 60));
    logWidget->show();
    logWidget->setFocus();
    logWidget->raise();

    logWidget->logModel->Clear();
    LogUpdates log;
    Controller::getInstance()->getLog(log, UserData::getInstance()->userId,
                                      std::make_shared<GetLogCallback>(logWidget));
}


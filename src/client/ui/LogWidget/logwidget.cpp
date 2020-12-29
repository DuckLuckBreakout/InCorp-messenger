#include "logwidget.h"
#include "ui_logwidget.h"
#include <QDebug>

LogWidget::LogWidget(QWidget *parent)
    :QFrame(parent),
    ui(new Ui::LogWidget) {
    ui->setupUi(this);
    this->setFrameShadow(QFrame::Raised);
    this->setMinimumWidth(260);
    this->setWindowFlags(Qt::Popup);
    QPalette Pal(palette());
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    logModel = std::make_shared<LogModel>();
    ui->logList->setModel(logModel.get());

    logDelegate = new LogDelegate(this);
    ui->logList->setItemDelegate(logDelegate);
}

LogWidget::~LogWidget() {
    delete ui;
}
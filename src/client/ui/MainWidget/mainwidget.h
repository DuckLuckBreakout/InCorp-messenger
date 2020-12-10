#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QStackedWidget>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QtWidgets/QAbstractItemView>

#include <ChatObjects/Message.h>
#include <Controller/Controller.h>
#include "ui/Views/Models/ChatModel/chatmodel.h"
#include "ui/Views/Delegates/ChatDelegate/chatdelegate.h"


namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget, public std::enable_shared_from_this<MainWidget>
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void after_login();
    void on_sendMessageButton_clicked();

public:
    std::shared_ptr<ChatModel> chatModel;
protected:
    Ui::MainWidget *ui;
    ChatDelegate *chatDelegate;
};


#endif // MAINWIDGET_H

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
#include "ui/Views/Models/GroupModel/groupmodel.h"
#include "ui/Views/Delegates/GroupDelegate/groupdelegate.h"
#include "ui/MenuWidget/menuwidget.h"

#include "ui/Views/Models/ChatModel/chatmodel.h"
#include "ui/Views/Models/GroupModel/groupmodel.h"
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

    void wheelEvent(QWheelEvent *event) override;

public slots:
    void afterLogin();
    void setChatRoomInfo(const ChatRoom& chatRoom);
    void on_sendMessageButton_clicked();
    void on_menuButton_clicked();
    void on_groupList_clicked(const QModelIndex& index);


public:
    std::shared_ptr<ChatModel> chatModel;
    std::shared_ptr<GroupModel> groupModel;
protected:
    Ui::MainWidget *ui;
    ChatDelegate *chatDelegate;
    GroupDelegate *groupDelegate;
    MenuWidget *menuWidget;
};


#endif // MAINWIDGET_H

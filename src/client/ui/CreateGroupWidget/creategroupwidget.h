#ifndef CREATEGROUPWIDGET_H
#define CREATEGROUPWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <memory>
#include <app-qt/src/models/groupmodel.h>
#include <app-qt/src/models/usermodel.h>
#include <app-qt/src/models/friendsmodel.h>
#include <app-qt/src/proxy/friendmodelproxy.h>
#include <app-qt/src/addfriendwidget/addfriendwidget.h>
namespace Ui {
class CreateGroupWidget;
}
enum class WidgetType{
    CREATE_GROUP,
    CONTACTS
};

class CreateGroupWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit CreateGroupWidget(QWidget *parent = nullptr);
    ~CreateGroupWidget();
    void setWidget(WidgetType type);
    std::shared_ptr<FriendsModel> getFriendsModel();
public slots:
    void on_pushButton_clicked();
    void on_closeContactsButton_clicked();
    void on_SearchEditToCreateGroup_textChanged(const QString &arg1);

    void on_SearchLineEditFriends_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();
    void on_addFriend(const QString &str);
    void on_addFriendButton_clicked();
    void getListFriend();
    void updateOnAddFfriend();

signals:
    void text_changed(const QString&);
    void groupCreated(const inf::ChatRoom &);
    void addFrinedSignal(const QString &str);
    void closeMenu();

private:
    Ui::CreateGroupWidget *ui;
    QWidget *createWidget;
    QWidget *contactsWidget;
    addFriendWidget *addFriend;
    FriendModelProxy *proxy;
    std::shared_ptr<FriendsModel> friendModel;

};

#endif // CREATEGROUPWIDGET_H

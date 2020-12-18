#ifndef GROUPMODEL_H
#define GROUPMODEL_H

#include <QAbstractListModel>
#include <functional>
#include <memory>

#include <ChatObjects/ChatItem.h>
#include "ui/Views/Models/ChatModel/chatmodel.h"


class GroupView : public ChatItem {
public:
    GroupView() = default;
    GroupView(ChatItem &item)
        :ChatItem(std::move(item)){}

public:
    MessageView lastMessage;
};

Q_DECLARE_METATYPE(GroupView)
class GroupModel : public QAbstractListModel, public std::enable_shared_from_this<GroupModel>
{
    Q_OBJECT
public:
    GroupModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void addItem(GroupView &item);
    void setData(std::vector<ChatItem> &);
    void addCallbacks();

    std::vector<GroupView> getItems();
    MessageView getLastMsg(int id) const;
    std::vector<GroupView> items;
private:
    std::optional<std::string> errString;

    int currentChatId;

signals:
    void chatRoomInfo(const ChatRoom& chatRoom);
    void addNewMessage(const Message& message);
    void updateItems();
    void messageChecked();
    void deleteMsg(int pos);
    void editMsg(const MessageView& msg);
public slots:
    void messageCreateByUser(const MessageView &msg);
    void setLastMessage(const MessageView &msg);
};

#endif // GROUPMODEL_H

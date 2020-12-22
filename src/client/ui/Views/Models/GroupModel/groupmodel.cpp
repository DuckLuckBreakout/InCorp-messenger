#include "groupmodel.h"
#include <QDebug>
#include <chrono>
#include "ui/Callbacks/Chat.h"

GroupModel::GroupModel(QObject *parent)
    : QAbstractListModel(parent){}

int GroupModel::rowCount(const QModelIndex &parent) const {
    return items.size();
}

QVariant GroupModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
           return QVariant();

    if (index.row() >= items.size())
        return QVariant();

    if (role == Qt::DisplayRole) {
        GroupView item = items.at(index.row());
        return QVariant::fromValue(item);
    }
    else
        return QVariant();
}

void GroupModel::addItem(GroupView& item) {
    int row = this->rowCount();
    beginInsertRows(QModelIndex(),row,row);
    items.emplace_back(item);

    endInsertRows();
}

void GroupModel::setData(std::vector<ChatItem>& chats) {
    items.clear();
    int row = this->rowCount();
    beginInsertRows(QModelIndex(), row, row + chats.size() - 1);
    for (auto &obj : chats)
        items.emplace_back(obj);

    auto controller = Controller::getInstance();

    for (size_t i = 0; i < items.size(); ++i) {
        Message message(items[i].chatId, "", 0, 0, 1);
        Controller::getInstance()->getLastMessage(message, UserData::getInstance()->userId,
                                                 std::make_shared<GetLastMessageCallback>(shared_from_this()));
        Controller::getInstance()->setChatObserver(items[i].chatId, std::make_shared<ChatObserverCallback>(shared_from_this()));
    }


    endInsertRows();
}

void GroupModel::newChat(ChatItem& chat) {
    int row = this->rowCount();
    beginInsertRows(QModelIndex(), row, row + 1);

    items.emplace_back(chat);

    auto controller = Controller::getInstance();

    int index = items.size() - 1;
    Message message(items[index].chatId, "", 0, 0, 1);
    Controller::getInstance()->getLastMessage(message, UserData::getInstance()->userId,
                                              std::make_shared<GetLastMessageCallback>(shared_from_this()));
    Controller::getInstance()->setChatObserver(items[index].chatId, std::make_shared<ChatObserverCallback>(shared_from_this()));


    endInsertRows();
}

std::vector<GroupView> GroupModel::getItems() {
    return items;
}

MessageView GroupModel::getLastMsg(int id) const {
    auto it = std::find_if(items.begin(), items.end(),[id](const GroupView &chat){
        return  chat.chatId == id;
    });
    if(it != items.end()){
        return it.base()->lastMessage;
    }
}

void GroupModel::messageCreateByUser(const MessageView &msg)
{
    auto it = std::find_if(items.begin(), items.end(),[msg](const GroupView &chat){
        return  chat.chatId == msg.chatId;
    });
    it.base()->lastMessage = msg;
}

void GroupModel::setLastMessage(const MessageView &msg)
{
    auto it = std::find_if(items.begin(),items.end(),[msg](GroupView &chat){
        return msg.chatId == chat.chatId;
    });
    if(it != items.end()){
        it->lastMessage = msg;
    }
    this->updateItems();
}


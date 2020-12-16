#include "chatmodel.h"
#include <memory>
#include <QDebug>
#include <unordered_set>
#include <QPixmap>
#include <ui/Callbacks/Chat.h>

ChatModel::ChatModel(QObject *parent)
    :QAbstractListModel(parent) {}

int ChatModel::rowCount(const QModelIndex &parent) const {
     return items.size();
}

QVariant ChatModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= items.size())
        return QVariant();

    if (role == Qt::DisplayRole) {
        auto item = items.at(index.row());
        return QVariant::fromValue(item);
    }
    else
        return QVariant();
}

void ChatModel::createMessage(const Message& message) {
    QByteArray array;

    int row = this->rowCount();
    beginInsertRows(QModelIndex(),row,row + 1);
    if(message.text != "") {
        std::cout << message.text << std::endl;
        items.emplace_back(MessageView(message));
    }
    endInsertRows();
    emit updateItems();
}

void ChatModel::newMessage(const Message& message) {
    int row = this->rowCount();
    beginInsertRows(QModelIndex(),row,row + 1);
    int myId = UserData::getInstance()->userId;

    items.emplace_back(MessageView(message));
    if (message.isChecked)
        items[items.size() - 1].type = MessageView::MessageType::MESSAGE_WAS_READ;
    else
        items[items.size() - 1].type = MessageView::MessageType::MESSAGE_WAS_SEND;

    User user(message.ownerId, message.chatId);
    Controller::getInstance()->getUser(user, UserData::getInstance()->userId,
                                       std::make_shared<GetUserForChatCallback>(shared_from_this()));

    endInsertRows();
    emit updateItems();
}


void ChatModel::messagesChecked() {
    int id = UserData::getInstance()->userId;
    std::for_each(items.begin(),items.end(),[id](MessageView& message) {
            if(message.ownerId == id)
                message.type = MessageView::MessageType::MESSAGE_WAS_READ;
    });
}

void ChatModel::updateMessageStatus(unsigned int number, MessageView::MessageType type) {
    std::for_each(items.begin(),items.end(),[number, type](MessageView& message) {
        if(message.number == number)
            message.type = type;
    });
}


void ChatModel::setData(std::vector<Message>& messages) {
    if (!messages.empty()) {
        int row = this->rowCount();
        auto uniqIds = getUniqueIds(messages);
        auto chatId = messages[0].chatId;

        beginInsertRows(QModelIndex(), row, row + messages.size() - 1);
        int myId = UserData::getInstance()->userId;
        for (auto &object : messages) {
            items.emplace_back(Message(object));
            if (object.isChecked)
                items[items.size() - 1].type = MessageView::MessageType::MESSAGE_WAS_READ;
            else
                items[items.size() - 1].type = MessageView::MessageType::MESSAGE_WAS_SEND;
        }

        for (auto &object : uniqIds) {
            User user(object, chatId);
            Controller::getInstance()->getUser(user, UserData::getInstance()->userId,
                                               std::make_shared<GetUserForChatCallback>(shared_from_this()));
        }
    }

    endInsertRows();
    emit updateItems();
}

std::vector<MessageView> ChatModel::getItems() {
    return items;
}


void ChatModel::Clear() {
    beginResetModel();
    items.clear();
    endResetModel();
}


std::vector<int> ChatModel::getUniqueIds(const std::vector<Message>& vector) {
    std::unordered_set<int> set;
    std::for_each(vector.begin(),vector.end(),[&set](const Message& message) {
        set.insert(message.ownerId);
    });
    return std::vector<int>(set.begin(),set.end());
}



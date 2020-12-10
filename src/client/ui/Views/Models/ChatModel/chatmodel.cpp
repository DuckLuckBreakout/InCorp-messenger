#include "chatmodel.h"
#include <memory>
#include <QDebug>
#include <unordered_set>
#include <QPixmap>

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

void ChatModel::newMessages(const std::vector<Message>& messages) {
    int row = this->rowCount();
    auto uniqIds = getUniqueIds(messages);
    beginInsertRows(QModelIndex(),row,row + messages.size());
    int myId = UserData::getInstance()->userId;

    for (auto& object : messages) {
        items.emplace_back(MessageView(object));
        if(object.isChecked && (object.ownerId == myId)) {
            items[items.size() - 1].type = MessageView::MessageType::READ_MESSAGE;
        }
        else if(object.ownerId == myId) {
             items[items.size() - 1].type = MessageView::MessageType::SELF_MESSAGE_DONE;
            }
        else{
            items[items.size() - 1].type = MessageView::MessageType::OTHER_MESSAGE;
        }
    }
    // TODO: Controller::getInstance()->getUser()

    endInsertRows();
    emit updateItems();
}

void ChatModel::messagesChecked() {
    int id = UserData::getInstance()->userId;
    std::for_each(items.begin(),items.end(),[id](MessageView& message) {
            if(message.ownerId == id)
                message.type = MessageView::MessageType::READ_MESSAGE;
    });
}

void ChatModel::updateMessageStatus(unsigned int number, MessageView::MessageType type) {
    std::for_each(items.begin(),items.end(),[number, type](MessageView& message) {
        if(message.number == number)
            message.type = type;
    });
}


void ChatModel::setData(std::vector<Message>& messages) {
    int row = this->rowCount();
    auto uniqIds = getUniqueIds(messages);
    beginInsertRows(QModelIndex(),row,row + messages.size());
    int myId = UserData::getInstance()->userId;
    for (auto& object : messages) {
        items.emplace_back(Message(object));
        if (object.isChecked && (object.ownerId == myId)) {
            items[items.size() - 1].type = MessageView::MessageType::READ_MESSAGE;
        }
        else if (object.ownerId == myId) {
             items[items.size() - 1].type = MessageView::MessageType::SELF_MESSAGE_DONE;
        }
        else {
            items[items.size() - 1].type = MessageView::MessageType::OTHER_MESSAGE;
        }
    }

    // TODO: Controller::getInstance()->getUser();

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



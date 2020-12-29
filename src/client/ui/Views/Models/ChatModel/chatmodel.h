#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QAbstractListModel>
#include <memory>
#include <time.h>

#include <ChatObjects/Message.h>
#include <Controller/Controller.h>
#include "ui/UserData/UserData.h"


class MessageView : public Message {
public:
    MessageView() {
        type = MessageType::MESSAGE_WAS_NOT_SEND;
    }

    explicit MessageView(const Message& item)
    : Message(item) {
        type = MessageType::MESSAGE_WAS_NOT_SEND;
        char buffer [100];
        strftime(buffer, 100,"%H:%M", localtime(&item.timeSend));
        time = QString::fromStdString(std::string(buffer));
    }

public:
    enum MessageType{
        MESSAGE_WAS_NOT_SEND,
        MESSAGE_WAS_SEND,
        MESSAGE_WAS_READ
    };

    MessageType type;
    QString time;
    QString firstName;
    QString lastName;
    QString role;
};

Q_DECLARE_METATYPE(MessageView);
Q_DECLARE_METATYPE(std::vector<Message>);
class ChatModel : public QAbstractListModel, public std::enable_shared_from_this<ChatModel>
{
    Q_OBJECT
public:
    ChatModel(QObject *parent = nullptr);

    void setData(std::vector<Message>& messages);
    std::vector<MessageView> getItems();
    void updateMessageStatus(unsigned int number, MessageView::MessageType type);
    void Clear();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

protected:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    std::vector<int> getUniqueIds(const std::vector<Message>& vec);


public slots:
    void createMessage(const Message& message);
    void newMessage(const Message& message);
    void checkMessages();
signals:
    void messageCreateByUser(const MessageView& message);
    void updateItems();
    void setLastMessageInGroup(const MessageView& message);

public:
    std::vector<MessageView> items;
private:
    std::optional<std::string> errString;
};


#endif // CHATMODEL_H

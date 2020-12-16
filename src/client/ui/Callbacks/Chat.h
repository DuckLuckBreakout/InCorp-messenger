#ifndef APPLICATION_CHAT_H
#define APPLICATION_CHAT_H

#include <QObject>

#include <CallbacksHolder/Callback/BaseCallback.h>
#include <ChatObjects/ChatUpdates.h>
#include <Controller/Controller.h>
#include "ui/LoginWidget/loginwidget.h"
#include "ui/MainWidget/mainwidget.h"


class SendMessageCallback : public BaseCallback {
public:
    SendMessageCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {

        auto message = std::static_pointer_cast<Message>(data);
        widget->chatModel->updateMessageStatus(message->number, MessageView::MessageType::MESSAGE_WAS_NOT_SEND);
        emit widget->chatModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};


class UpdateMessagesCallback : public BaseCallback {
public:
    UpdateMessagesCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto updates = std::static_pointer_cast<ChatUpdates>(data);
        widget->chatModel->setData(updates->messages);
        emit widget->chatModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};

class GetChatMessagesCallback : public BaseCallback {
public:
    GetChatMessagesCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto updates = std::static_pointer_cast<ChatUpdates>(data);
        widget->chatModel->setData(updates->messages);

        if (updates->messages.size() == updates->maxNumMessages) {
            ChatUpdates chatUpdates(updates->chatId, updates->lastMessageNum + updates->maxNumMessages,
                                    updates->maxNumMessages);
            Controller::getInstance()->chatUpdate(chatUpdates, UserData::getInstance()->userId,
                                                    std::make_shared<GetChatMessagesCallback>(widget));
        }
        emit window->chatModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};

class GetListChatsCallback : public BaseCallback {
public:
    GetListChatsCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto list = std::static_pointer_cast<ListChats>(data);

        window ->groupModel->setData(list->chats);
        emit window->groupModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};

class GetChatRoomCallback : public BaseCallback {
public:
    GetChatRoomCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto chatRoom = std::static_pointer_cast<ChatRoom>(data);
        emit window->groupModel->chatRoomInfo(*chatRoom);
    }

private:
    std::shared_ptr<MainWidget> widget;
};

class GetUserForChatCallback : public BaseCallback {
public:
    GetUserForChatCallback(std::shared_ptr<ChatModel> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto user = std::static_pointer_cast<User>(data);
        std::for_each(widget->items.begin(),widget->items.end(),[user](MessageView& message){
            if (message.ownerId == user->userId){
                message.firstName = QString::fromStdString(user->firstName);
                message.lastName = QString::fromStdString(user->lastName);
                message.role = QString::fromStdString(user->role);
            }
        });
        emit window->updateItems();
    }

private:
    std::shared_ptr<ChatModel> widget;
};


class GetUserForGroupCallback : public BaseCallback {
public:
    GetUserForGroupCallback(std::shared_ptr<GroupModel> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto user = std::static_pointer_cast<User>(data);

        std::for_each(widget->items.begin(),widget->items.end(),[user](GroupView &group) {
            if (group.lastMessage.ownerId == user->userId){
                group.lastMessage.firstName = QString::fromStdString(user->firstName);
                group.lastMessage.lastName = QString::fromStdString(user->lastName);
                group.lastMessage.role = QString::fromStdString(user->role);
            }
        });
        emit window->updateItems();
    }

private:
    std::shared_ptr<GroupModel> widget;
};

class GetLastMessageCallback : public BaseCallback {
public:
    GetLastMessageCallback(std::shared_ptr<GroupModel> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto message = std::static_pointer_cast<Message>(data);
        auto it = std::find_if(widget->items.begin(),
                               widget->items.end(),[message](const GroupView &chat) {
                    return  chat.chatId == message->chatId;
                });
        MessageView newMessage(*message);
        it.base()->lastMessage = newMessage;
        User user(newMessage.ownerId, message->chatId);
        Controller::getInstance()->getUser(user, UserData::getInstance()->userId,
                                           std::make_shared<GetUserForGroupCallback>(window));

        emit window->updateItems();
    }

private:
    std::shared_ptr<GroupModel> widget;
};

class ChatObserverCallback : public BaseCallback {
public:
    ChatObserverCallback(std::shared_ptr<GroupModel> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto message = std::static_pointer_cast<Message>(data);
        if (message->ownerId == UserData::getInstance()->currentChatId) {
            emit window->addNewMessage(*message);
        }
        auto it = std::find_if(widget->items.begin(),widget->items.end(),[message](GroupView &chat){
            return chat.chatId == message->chatId;
        });

        MessageView newMessage(*message);
        it.base()->lastMessage = newMessage;
        User user(newMessage.ownerId, newMessage.chatId);
        Controller::getInstance()->getUser(user, UserData::getInstance()->userId,
                                           std::make_shared<GetUserForGroupCallback>(widget));
        emit window->updateItems();
    }

private:
    std::shared_ptr<GroupModel> widget;
};

#endif //APPLICATION_CHAT_H

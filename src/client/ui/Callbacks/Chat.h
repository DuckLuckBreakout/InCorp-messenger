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
    void operator()(std::shared_ptr<BaseObject> data) override {

        auto message = std::static_pointer_cast<Message>(data);
        widget->chatModel->updateMessageStatus(message->number, MessageView::MessageType::SELF_MESSAGE_DONE);
        emit widget->chatModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};


class UpdateMessagesCallback : public BaseCallback {
public:
    UpdateMessagesCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data) override {
        auto updates = std::static_pointer_cast<ChatUpdates>(data);
        widget->chatModel->setData(updates->messages);
        emit widget->chatModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};


#endif //APPLICATION_CHAT_H

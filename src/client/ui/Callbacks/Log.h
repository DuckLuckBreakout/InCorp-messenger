#ifndef APPLICATION_LOGS_H
#define APPLICATION_LOGS_H

#include <QObject>

#include <CallbacksHolder/Callback/BaseCallback.h>
#include <ChatObjects/ChatUpdates.h>
#include <Controller/Controller.h>
#include "ui/LogWidget/logwidget.h"
#include "ui/MenuWidget/menuwidget.h"


// Callback for Get Log
class GetLogCallback : public BaseCallback {
public:
    GetLogCallback(LogWidget* widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto updates = std::static_pointer_cast<LogUpdates>(data);
        window->logModel->setData(updates->logs);
        if (updates->logs.size() == updates->maxNumMessages) {
            LogUpdates logUpdates(updates->lastMessageNum + updates->maxNumMessages,
                                  updates->maxNumMessages);
            Controller::getInstance()->getLog(logUpdates, UserData::getInstance()->userId,
                                              std::make_shared<GetLogCallback>(widget));
        }
        emit window->logModel->updateItems();
    }

private:
    LogWidget* widget;
};

#endif //APPLICATION_LOGS_H

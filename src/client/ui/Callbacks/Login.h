#ifndef APPLICATION_LOGIN_H
#define APPLICATION_LOGIN_H

#include <QObject>

#include <CallbacksHolder/Callback/BaseCallback.h>
#include <Controller/Controller.h>
#include "ui/LoginWidget/loginwidget.h"
#include "ui/LoginWidget/loginwidget.h"
#include "ui/UserData/UserData.h"


class LoginCallback : public BaseCallback {
public:
    LoginCallback(std::shared_ptr<LoginWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data) override {

        auto authInfo = std::static_pointer_cast<Authorization>(data);

        auto userData = UserData::getInstance();
        userData->userId = authInfo->userId;
        userData->firstName = authInfo->firstName;
        userData->lastName = authInfo->lastName;
        userData->role = authInfo->role;
        userData->chatsId = authInfo->chatsId;

        widget->showMainWidget();
        Controller::getInstance()->reconnectClient(authInfo->ip, authInfo->port);
    }

private:
    std::shared_ptr<LoginWidget> widget;
};


#endif //APPLICATION_LOGIN_H

#ifndef APPLICATION_LOGIN_H
#define APPLICATION_LOGIN_H

#include <QObject>
#include <QMessageBox>

#include <CallbacksHolder/Callback/BaseCallback.h>
#include <Controller/Controller.h>
#include "ui/LoginWidget/loginwidget.h"
#include "ui/MainWidget/mainwidget.h"
#include "ui/UserData/UserData.h"


class LoginCallback : public BaseCallback {
public:
    LoginCallback(std::shared_ptr<LoginWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        if (error)
            widget->ui->SignInLabel->setText(QString::fromStdString("Sing in error: " + (*error)));
        else {
            auto authInfo = std::static_pointer_cast<Authorization>(data);
            auto userData = UserData::getInstance();
            userData->company = authInfo->company;
            userData->userId = authInfo->userId;
            userData->firstName = authInfo->firstName;
            userData->lastName = authInfo->lastName;
            userData->role = authInfo->role;

            auto window = widget;
            Controller::getInstance()->reconnectClient(authInfo->ip, authInfo->port);
            window->showMainWidget();
        }
    }

private:
    std::shared_ptr<LoginWidget> widget;
};


#endif //APPLICATION_LOGIN_H

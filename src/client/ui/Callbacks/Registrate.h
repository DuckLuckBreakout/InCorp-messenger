#ifndef APPLICATION_REGISTRATE_H
#define APPLICATION_REGISTRATE_H

#include <QObject>
#include <QMessageBox>

#include <CallbacksHolder/Callback/BaseCallback.h>
#include <Controller/Controller.h>
#include "ui/RegistrateWidget/registratewidget.h"

#include "ui/UserData/UserData.h"


// Callback for Registrate
class RegistrationCallback : public BaseCallback {
public:
    RegistrationCallback(RegistrateWidget* widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        if (error)
            widget->setErrorStatus(QString::fromStdString("Sing up error: " + (*error)));

        else {
            auto authInfo = std::static_pointer_cast<UserInfo>(data);
            widget->setSuccessStatus(QString::fromStdString(authInfo->firstName +
                                                            " " + authInfo->lastName + " was registered"));
        }
    }

private:
    RegistrateWidget* widget;
};


#endif //APPLICATION_REGISTRATE_H

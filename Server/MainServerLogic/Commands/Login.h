#ifndef SERVER_LOGIN_H
#define SERVER_LOGIN_H

#include "BaseCommand.h"

class Login: public BaseCommand {
public:
    ~Login() override = default;

    void execute(std::shared_ptr<Controller> controller) override;
};


#endif //SERVER_LOGIN_H

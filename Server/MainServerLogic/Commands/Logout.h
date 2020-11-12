#ifndef SERVER_LOGOUT_H
#define SERVER_LOGOUT_H

#include "BaseCommand.h"

class Logout: public BaseCommand {
public:
    ~Logout() override = default;

    void execute(std::shared_ptr<Controller> controller) override;
};


#endif //SERVER_LOGOUT_H

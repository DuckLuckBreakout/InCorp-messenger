#ifndef SERVER_LOGOUT_H
#define SERVER_LOGOUT_H

#include "BaseCommand.h"

class Logout: public BaseCommand {
public:
    explicit Logout(boost::property_tree::ptree &params);
    ~Logout() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};


#endif //SERVER_LOGOUT_H

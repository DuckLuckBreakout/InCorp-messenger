#ifndef SERVER_LOGIN_H
#define SERVER_LOGIN_H

#include "BaseCommand.h"

/*
 * User login command class
 */
class Login: public BaseCommand {
public:
    explicit Login(boost::property_tree::ptree& params);
    ~Login() override = default;
    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};


#endif //SERVER_LOGIN_H

#ifndef TP_PPROJECT_CONTROLLER_H
#define TP_PPROJECT_CONTROLLER_H

#include <iostream>
#include "Server/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"

class Controller {
public:
    Controller();
    ~Controller() = default;

    boost::property_tree::ptree loginUser(boost::property_tree::ptree &params);
private:
    std::shared_ptr<AuthorizationManager> authorizationManager;
};


#endif //TP_PPROJECT_CONTROLLER_H

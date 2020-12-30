#ifndef TP_PPROJECT_CONTROLLER_H
#define TP_PPROJECT_CONTROLLER_H

#include <iostream>
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/ChatManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/RegistrationManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/CommandsManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/LogsManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/InfoManager.h"

/*
 * Class responsible for calling the appropriate managers to execute the command
 */
class Controller {
public:
    Controller();
    ~Controller() = default;

    /*
     * Calling login method of authorization manager
     */
    boost::property_tree::ptree loginUser(boost::property_tree::ptree &params);
private:
    std::shared_ptr<AuthorizationManager> authorizationManager;
};



#endif //TP_PPROJECT_CONTROLLER_H

#ifndef TP_PPROJECT_CONTROLLER_H
#define TP_PPROJECT_CONTROLLER_H

#include <iostream>
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/ChatManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"

class Controller {
public:
    Controller();
    ~Controller() = default;

    boost::property_tree::ptree loginUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree logoutUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree sendMessage(boost::property_tree::ptree &params);
    boost::property_tree::ptree updateChats(boost::property_tree::ptree &params);
    boost::property_tree::ptree deleteChat(boost::property_tree::ptree &params);
    boost::property_tree::ptree createChat(boost::property_tree::ptree &params);
    boost::property_tree::ptree deleteUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree createUser(boost::property_tree::ptree &params);
private:
    std::shared_ptr<ChatManager> chatManager;
    std::shared_ptr<AuthorizationManager> authorizationManager;
};


#endif //TP_PPROJECT_CONTROLLER_H

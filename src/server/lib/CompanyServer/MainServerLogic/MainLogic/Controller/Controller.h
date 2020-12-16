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
    boost::property_tree::ptree command1(boost::property_tree::ptree &params);
    boost::property_tree::ptree command2(boost::property_tree::ptree &params);
    boost::property_tree::ptree command3(boost::property_tree::ptree &params);
    boost::property_tree::ptree command4(boost::property_tree::ptree &params);
    boost::property_tree::ptree command5(boost::property_tree::ptree &params);
    boost::property_tree::ptree command6(boost::property_tree::ptree &params);
    boost::property_tree::ptree command7(boost::property_tree::ptree &params);
    boost::property_tree::ptree command8(boost::property_tree::ptree &params);
private:
    std::shared_ptr<ChatManager> chatManager;
    std::shared_ptr<AuthorizationManager> authorizationManager;
};



#endif //TP_PPROJECT_CONTROLLER_H

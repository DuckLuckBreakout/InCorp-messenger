#ifndef TP_PPROJECT_CONTROLLER_H
#define TP_PPROJECT_CONTROLLER_H

#include <iostream>
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/ChatManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/RegistrationManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/CommandsManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/LogsManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/InfoManager.h"

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
    boost::property_tree::ptree getUserChatsPreview(boost::property_tree::ptree &params);
    boost::property_tree::ptree getChatInfo(boost::property_tree::ptree &params);
    boost::property_tree::ptree getChatMessages(boost::property_tree::ptree &params);
    boost::property_tree::ptree getChatLastMessage(boost::property_tree::ptree &params);
    boost::property_tree::ptree getMessageAuthorInfo(boost::property_tree::ptree &params);
    boost::property_tree::ptree getServerLogs(boost::property_tree::ptree &params);
    boost::property_tree::ptree command(boost::property_tree::ptree &params);
    boost::property_tree::ptree registerUser(boost::property_tree::ptree &params);
private:
    std::shared_ptr<ChatManager> chatManager;
    std::shared_ptr<AuthorizationManager> authorizationManager;
    std::shared_ptr<RegistrationManager> registrationManager;
    std::shared_ptr<CommandsManager> commandsManager;
    std::shared_ptr<LogsManager> logsManager;
    std::shared_ptr<InfoManager> infoManager;
};



#endif //TP_PPROJECT_CONTROLLER_H

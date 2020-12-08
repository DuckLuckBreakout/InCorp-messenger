#ifndef TP_PPROJECT_CONTROLLER_H
#define TP_PPROJECT_CONTROLLER_H

#include <iostream>
#include "Server/MainServerLogic/MainLogic/Managers/ChatManager.h"
#include "Server/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"

class Controller {
public:
    Controller();
    ~Controller() = default;

    void loginUser(std::shared_ptr<BaseConnection>& connection, std::string token);
    void logoutUser(std::shared_ptr<BaseConnection>& connection);
    void sendMessage(std::string message, int chatID);
    void updateChats();
    void deleteChat(int chatID);
    void createChat();
private:
    std::shared_ptr<ChatManager> chatManager;
    std::shared_ptr<AuthorizationManager> authorizationManager;
};


#endif //TP_PPROJECT_CONTROLLER_H

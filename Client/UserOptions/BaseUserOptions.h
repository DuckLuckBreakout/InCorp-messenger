#ifndef TP_PPROJECT_BASEUSEROPTIONS_H
#define TP_PPROJECT_BASEUSEROPTIONS_H

#include "Client/Manager/AuthorizationManager.h"
#include "Client/Manager/ChatManager.h"

class BaseUserOptions {
public:
    virtual ~BaseUserOptions() = default;

    virtual void login(std::shared_ptr<BaseConnection>& connection,
                       const std::string& token) = 0;
    virtual void logout(std::shared_ptr<BaseConnection>& connection) = 0;
    virtual void sendMessage(std::shared_ptr<BaseConnection>& connection,
                             int chatId, const std::string& message) = 0;
    virtual void updateChats(std::shared_ptr<BaseConnection>& connection) = 0;
    virtual void createChat(std::shared_ptr<BaseConnection>& connection,
                            const std::string& chatName) = 0;

protected:
    ChatManager chatManager;
    AuthorizationManager authorizationManager;
};


#endif

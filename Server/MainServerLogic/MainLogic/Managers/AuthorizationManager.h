#ifndef SERVER_AUTHORIZATIONMANAGER_H
#define SERVER_AUTHORIZATIONMANAGER_H

#include "BaseManager.h"
#include "src/libs/Connection/BaseConnection.h"

class AuthorizationManager: public BaseManager {
public:
    ~AuthorizationManager() override = default;

    void loginUser(std::shared_ptr<BaseConnection>& connection, std::string token);
    void logoutUser(std::shared_ptr<BaseConnection>& connection);
};

#endif //SERVER_AUTHORIZATIONMANAGER_H

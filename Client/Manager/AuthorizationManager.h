#ifndef TP_PPROJECT_AUTHORIZATIONMANAGER_H
#define TP_PPROJECT_AUTHORIZATIONMANAGER_H

#include <memory>

#include "BaseManager.h"
#include "src/libs/Connection/BaseConnection.h"

class AuthorizationManager : public BaseManager {
public:
    ~AuthorizationManager() override = default;

    void login(std::shared_ptr<BaseConnection>& connection,
               std::string token);
    void logout(std::shared_ptr<BaseConnection>& connection);
};

#endif

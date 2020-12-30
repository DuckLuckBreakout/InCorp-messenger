#ifndef SERVER_AUTHORIZATIONMANAGER_H
#define SERVER_AUTHORIZATIONMANAGER_H

#include <boost/property_tree/ptree.hpp>
#include "BaseManager.h"
#include "src/server/lib/Connection/BaseConnection.h"

class AuthorizationManager: public BaseManager {
public:
    ~AuthorizationManager() override = default;

    boost::property_tree::ptree loginUser(boost::property_tree::ptree &params);
};

#endif //SERVER_AUTHORIZATIONMANAGER_H

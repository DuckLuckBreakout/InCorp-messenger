#ifndef APPLICATION_REGISTRATIONMANAGER_H
#define APPLICATION_REGISTRATIONMANAGER_H


#include <boost/property_tree/ptree.hpp>
#include "BaseManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/DataBaseConnector/DataBaseConnector.h"
#include "src/server/lib/Connection/BaseConnection.h"

class RegistrationManager: public BaseManager {
public:
    ~RegistrationManager() override = default;
    boost::property_tree::ptree deleteUser(boost::property_tree::ptree &params);
    boost::property_tree::ptree registerUser(boost::property_tree::ptree &params);
};


#endif //APPLICATION_REGISTRATIONMANAGER_H

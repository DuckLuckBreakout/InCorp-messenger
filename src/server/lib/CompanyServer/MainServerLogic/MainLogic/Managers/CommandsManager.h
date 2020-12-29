#ifndef APPLICATION_NOTIFICATIONMANAGER_H
#define APPLICATION_NOTIFICATIONMANAGER_H

#include "BaseManager.h"
#include <boost/property_tree/ptree.hpp>
#include "src/server/lib/Connection/BaseConnection.h"

class CommandsManager: public BaseManager {
public:
    ~CommandsManager() override = default;
    boost::property_tree::ptree command(boost::property_tree::ptree &params);

};

#endif //APPLICATION_NOTIFICATIONMANAGER_H

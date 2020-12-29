#ifndef APPLICATION_LOGSMANAGER_H
#define APPLICATION_LOGSMANAGER_H

#include "BaseManager.h"
#include <boost/property_tree/ptree.hpp>
#include "src/server/lib/Connection/BaseConnection.h"

class LogsManager: public BaseManager {
public:
    ~LogsManager() override = default;
    boost::property_tree::ptree getServerLogs(boost::property_tree::ptree &params);
};


#endif //APPLICATION_LOGSMANAGER_H

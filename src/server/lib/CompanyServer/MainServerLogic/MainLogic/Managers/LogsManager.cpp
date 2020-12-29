#include "LogsManager.h"


boost::property_tree::ptree LogsManager::getServerLogs(boost::property_tree::ptree &params) {
    dbConnector.getServerLogs(params);
    params.add("status", "true");
    params.add("error", "");
    return params;
}
#include "GetServerLogs.h"

boost::property_tree::ptree GetServerLogs::execute(std::shared_ptr<Controller> controller) {
    return controller->getServerLogs(commandParams);
}

GetServerLogs::GetServerLogs(boost::property_tree::ptree &params) : BaseCommand("GetLog") {
    commandParams = params;
}

#include "DeleteChat.h"

boost::property_tree::ptree DeleteChat::execute(std::shared_ptr<Controller> controller) {
    return controller->deleteChat(commandParams);
}

DeleteChat::DeleteChat(boost::property_tree::ptree &params) : BaseCommand("DeleteChat") {
    commandParams = params;
}

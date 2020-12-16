#include "WriteMessage.h"

boost::property_tree::ptree WriteMessage::execute(std::shared_ptr<Controller> controller) {
    return controller->sendMessage(commandParams);
}

WriteMessage::WriteMessage(boost::property_tree::ptree &params) {
    commandParams = params;
}

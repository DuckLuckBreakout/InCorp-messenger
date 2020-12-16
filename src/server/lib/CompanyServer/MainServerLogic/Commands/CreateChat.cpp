#include "CreateChat.h"

boost::property_tree::ptree CreateChat::execute(std::shared_ptr<Controller> controller) {
    return controller->createChat(commandParams);
}

CreateChat::CreateChat(boost::property_tree::ptree &params) {
    commandParams = params;
}

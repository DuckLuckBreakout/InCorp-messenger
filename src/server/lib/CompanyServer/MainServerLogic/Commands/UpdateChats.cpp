#include "UpdateChats.h"

boost::property_tree::ptree UpdateChats::execute(std::shared_ptr<Controller> controller) {
    return controller->updateChats(commandParams);
}

UpdateChats::UpdateChats(boost::property_tree::ptree &params) {
    commandParams = params;
}

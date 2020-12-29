#include "GetChatMessages.h"

boost::property_tree::ptree GetChatMessages::execute(std::shared_ptr<Controller> controller) {
    return controller->getChatMessages(commandParams);
}

GetChatMessages::GetChatMessages(boost::property_tree::ptree &params) : BaseCommand("GetMessagesInChat") {
    commandParams = params;
}

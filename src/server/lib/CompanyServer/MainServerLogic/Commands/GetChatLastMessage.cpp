#include "GetChatLastMessage.h"

boost::property_tree::ptree GetChatLastMessage::execute(std::shared_ptr<Controller> controller) {
    return controller->getChatLastMessage(commandParams);
}

GetChatLastMessage::GetChatLastMessage(boost::property_tree::ptree &params) : BaseCommand("GetLastMessageInChat") {
    commandParams = params;
}

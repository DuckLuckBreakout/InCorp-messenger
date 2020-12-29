#include "GetChatInfo.h"

boost::property_tree::ptree GetChatInfo::execute(std::shared_ptr<Controller> controller) {
    return controller->getChatInfo(commandParams);
}

GetChatInfo::GetChatInfo(boost::property_tree::ptree &params) : BaseCommand("GetSelectChatRoom") {
    commandParams = params;
}

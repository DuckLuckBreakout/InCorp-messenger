#include "GetUserChatsPreview.h"

boost::property_tree::ptree GetUserChatsPreview::execute(std::shared_ptr<Controller> controller) {
    return controller->getUserChatsPreview(commandParams);
}

GetUserChatsPreview::GetUserChatsPreview(boost::property_tree::ptree &params) : BaseCommand("GetListOfChats") {
    commandParams = params;
}

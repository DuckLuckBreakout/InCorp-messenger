#include "GetMessageAuthorInfo.h"

boost::property_tree::ptree GetMessageAuthorInfo::execute(std::shared_ptr<Controller> controller) {
    return controller->getMessageAuthorInfo(commandParams);
}

GetMessageAuthorInfo::GetMessageAuthorInfo(boost::property_tree::ptree &params) : BaseCommand("GetUserData") {
    commandParams = params;
}

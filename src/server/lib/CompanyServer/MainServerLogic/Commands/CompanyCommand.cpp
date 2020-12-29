#include "CompanyCommand.h"

boost::property_tree::ptree CompanyCommand::execute(std::shared_ptr<Controller> controller) {
    return controller->command(commandParams);
}

CompanyCommand::CompanyCommand(boost::property_tree::ptree &params) : BaseCommand("") {
commandParams = params;
}

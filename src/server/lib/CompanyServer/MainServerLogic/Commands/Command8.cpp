//
// Created by Иван Коваленко on 14.12.2020.
//

#include "Command8.h"

boost::property_tree::ptree Command8::execute(std::shared_ptr<Controller> controller) {
    return controller->command8(commandParams);
}

Command8::Command8(boost::property_tree::ptree &params) {
    commandParams = params;
}

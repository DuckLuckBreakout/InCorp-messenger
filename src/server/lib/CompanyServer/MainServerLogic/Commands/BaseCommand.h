#ifndef TP_PPROJECT_BASECOMMAND_H
#define TP_PPROJECT_BASECOMMAND_H

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Controller/Controller.h"

class BaseCommand {
public:
    virtual ~BaseCommand() = default;

    virtual boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) = 0;

public:
    boost::property_tree::ptree commandParams;
};
#endif //TP_PPROJECT_BASECOMMAND_H

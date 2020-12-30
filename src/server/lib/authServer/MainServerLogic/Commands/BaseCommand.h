#ifndef TP_PPROJECT_BASECOMMAND_H
#define TP_PPROJECT_BASECOMMAND_H

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Controller/Controller.h"

/*
 * Base command class
 */
class BaseCommand {
public:
    BaseCommand(const std::string &name) : name(name) {};
    virtual ~BaseCommand() = default;

    /*
     * Executing a command
     */
    virtual boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) = 0;

public:
    boost::property_tree::ptree commandParams;
    std::string name;
};
#endif //TP_PPROJECT_BASECOMMAND_H

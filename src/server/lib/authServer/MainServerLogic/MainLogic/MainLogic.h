#ifndef TP_PPROJECT_MAINLOGIC_H
#define TP_PPROJECT_MAINLOGIC_H

#include "src/server/lib/CompanyServer/MainServerLogic/Commands/BaseCommand.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Controller/Controller.h"

/*
 * The class responsible for sending the command for execution
 */
class MainLogic {
public:
    MainLogic();

    /*
     * Sending a command to execute
     */
    boost::property_tree::ptree executeCommand(std::shared_ptr<BaseCommand> command);
private:
    std::shared_ptr<Controller> controller;
};


#endif

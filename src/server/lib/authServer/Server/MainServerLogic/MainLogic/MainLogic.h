#ifndef TP_PPROJECT_MAINLOGIC_H
#define TP_PPROJECT_MAINLOGIC_H

#include "Server/MainServerLogic/Commands/BaseCommand.h"
#include "src/server/lib/authServer/Server/MainServerLogic/MainLogic/Controller/Controller.h"

class MainLogic {
public:
    MainLogic();
    boost::property_tree::ptree executeCommand(std::shared_ptr<BaseCommand> command);
private:
    std::shared_ptr<Controller> controller;
};


#endif //TP_PPROJECT_MAINLOGIC_H

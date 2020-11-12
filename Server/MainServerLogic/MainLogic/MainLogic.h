#ifndef TP_PPROJECT_MAINLOGIC_H
#define TP_PPROJECT_MAINLOGIC_H

#include "Server/MainServerLogic/Commands/BaseCommand.h"
#include "Controller/Controller.h"

class MainLogic {
public:
    MainLogic();
    void executeCommand(std::shared_ptr<BaseCommand> command);
private:
    std::shared_ptr<Controller> controller;
};


#endif //TP_PPROJECT_MAINLOGIC_H

#ifndef TP_PPROJECT_BASECOMMAND_H
#define TP_PPROJECT_BASECOMMAND_H

#include <iostream>
#include "../MainLogic/Controller/Controller.h"

class BaseCommand {
public:
    virtual ~BaseCommand() = default;

    virtual void execute(std::shared_ptr<Controller> controller) = 0;
};
#endif //TP_PPROJECT_BASECOMMAND_H

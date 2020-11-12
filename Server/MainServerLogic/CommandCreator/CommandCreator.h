#ifndef TP_PPROJECT_COMMANDPARSER_H
#define TP_PPROJECT_COMMANDPARSER_H

#include "Server/MainServerLogic/Commands/BaseCommand.h"

class CommandCreator {
public:
    std::shared_ptr<BaseCommand> createCommand(std::string message);
};

#endif

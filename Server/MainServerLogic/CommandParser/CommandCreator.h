#ifndef TP_PPROJECT_COMMANDPARSER_H
#define TP_PPROJECT_COMMANDPARSER_H

#include "../Commands/BaseCommand.h"

// TODO: CommandCreator
// switch ("read") -> create ReadCommand();
// return shared_ptr<BaseCommand>

class CommandCreator {
public:
    std::shared_ptr<BaseCommand> createCommand(std::string message);
};

#endif

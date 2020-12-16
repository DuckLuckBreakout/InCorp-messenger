#ifndef TP_PPROJECT_COMMANDPARSER_H
#define TP_PPROJECT_COMMANDPARSER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/BaseCommand.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Login.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Logout.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/WriteMessage.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/CreateChat.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/DeleteChat.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/DeleteUser.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/CreateUser.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Command1.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Command2.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Command3.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Command4.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Command5.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Command6.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Command7.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Command8.h"

enum Command {
    PING=-1,
    LOGIN,
    WRITE_MESSAGE,
    LOGOUT,
    CREATE_CHAT,
    DELETE_CHAT,
    DELETE_USER,
    CREATE_USER,
    COMMAND1=20,
    COMMAND2=21,
    COMMAND3=22,
    COMMAND4=23,
    COMMAND5=24,
    COMMAND6=25,
    COMMAND7=26,
    COMMAND8=27,
};

class CommandCreator {
public:
    std::shared_ptr<BaseCommand> createCommand(std::string message);
};

#endif

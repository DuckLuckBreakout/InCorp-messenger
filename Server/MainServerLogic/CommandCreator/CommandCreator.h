#ifndef TP_PPROJECT_COMMANDPARSER_H
#define TP_PPROJECT_COMMANDPARSER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "Server/MainServerLogic/Commands/BaseCommand.h"
#include "Server/MainServerLogic/Commands/Login.h"
#include "Server/MainServerLogic/Commands/Logout.h"
#include "Server/MainServerLogic/Commands/WriteMessage.h"
#include "Server/MainServerLogic/Commands/CreateChat.h"
#include "Server/MainServerLogic/Commands/DeleteChat.h"
#include "Server/MainServerLogic/Commands/DeleteUser.h"
#include "Server/MainServerLogic/Commands/CreateUser.h"

enum Command {
    PING=-1,
    LOGIN,
    WRITE_MESSAGE,
    LOGOUT,
    CREATE_CHAT,
    DELETE_CHAT,
    DELETE_USER,
    CREATE_USER
};

class CommandCreator {
public:
    std::shared_ptr<BaseCommand> createCommand(std::string message);
};

#endif

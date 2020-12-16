#ifndef TP_PPROJECT_COMMANDHANDLER_H
#define TP_PPROJECT_COMMANDHANDLER_H

#include <iostream>
#include <functional>
#include <boost/property_tree/ini_parser.hpp>
#include "Server/MainServerLogic/MainLogic/MainLogic.h"
#include "src/libs/Connection/BaseConnection.h"
#include "Server/MainServerLogic/CommandCreator/CommandCreator.h"

class CommandHandler {
public:
    CommandHandler();
    ~CommandHandler() = default;

    void runRequest(std::shared_ptr<BaseConnection> client);

private:
    CommandCreator parser;
    MainLogic mainLogic;
};


#endif //TP_PPROJECT_COMMANDHANDLER_H

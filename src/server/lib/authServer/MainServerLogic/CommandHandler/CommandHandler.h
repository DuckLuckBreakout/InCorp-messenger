#ifndef TP_PPROJECT_COMMANDHANDLER_H
#define TP_PPROJECT_COMMANDHANDLER_H

#include <iostream>
#include <functional>
#include <boost/property_tree/ini_parser.hpp>
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/MainLogic.h"
#include "src/server/lib/Connection/BaseConnection.h"
#include "src/server/lib/Connection/Connection.h"
#include "src/server/lib/CompanyServer/MainServerLogic/CommandCreator/CommandCreator.h"

/*
 * The class responsible for the execution of the received query
 */
class CommandHandler {
public:
    CommandHandler();
    ~CommandHandler() = default;

    /*
     * Executing a client request
     */
    void runRequest(const std::shared_ptr<Connection>& connection, std::string &message);

private:
    CommandCreator parser;
    MainLogic mainLogic;
};


#endif

#include "CommandHandler.h"

CommandHandler::CommandHandler() : parser(), mainLogic() {}

void CommandHandler::runRequest(std::shared_ptr<BaseConnection> connection) {
    std::shared_ptr<BaseCommand> command = parser.createCommand(connection->getRequest());
    boost::property_tree::ptree result = mainLogic.executeCommand(command);

    int commandNumber = result.get<int>("command");
    if (commandNumber == LOGIN) {
        std::string resultStatus = result.get<std::string>("status");
        if (resultStatus.length() == 0)
            connection->loginConfirmed = true;
        else
            connection->loginConfirmed = false;

        std::stringstream response;
        boost::property_tree::json_parser::write_json(response, result);
        connection->sendRequest(response.str()  + "\r\n");

    } else if (commandNumber == LOGOUT) {
        connection->loginConfirmed = false;

        std::stringstream response;
        boost::property_tree::json_parser::write_json(response, result);
        connection->sendRequest(response.str()  + "\r\n");
    } else {
        std::stringstream response;
        boost::property_tree::json_parser::write_json(response, result);
        connection->sendRequest(response.str() + "\r\n");
    }

}


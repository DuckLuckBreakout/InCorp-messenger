#include "CommandHandler.h"

CommandHandler::CommandHandler() : parser(), mainLogic() {}

void CommandHandler::runRequest(std::shared_ptr<BaseConnection> connection, std::string message) {
    try {
        std::shared_ptr<BaseCommand> command = parser.createCommand(message);

        boost::property_tree::ptree result = mainLogic.executeCommand(command);
        int commandNumber = result.get<int>("command");
        if (commandNumber == LOGIN) {
            std::string resultStatus = result.get<std::string>("status");

            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->on_message(response_str);

        } else if (commandNumber == LOGOUT) {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->on_message(response_str);

        } else {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->on_message(response_str);
        }
    }

    catch(...) {
        try {
//            connection->disconnect();
        }
        catch (...) {}    }
}


#include "CommandHandler.h"
#include "src/server/lib/Connection/Connection.h"
#include "src/server/lib/CompanyServer/Server/Server.h"

CommandHandler::CommandHandler() : parser(), mainLogic() {}


void CommandHandler::runRequest(const std::shared_ptr<Connection>& connection, std::string &message) {
    try {
        std::shared_ptr<BaseCommand> command = parser.createCommand(message);

        boost::property_tree::ptree result = mainLogic.executeCommand(command);
        int commandNumber = result.get<int>("command");

        if (commandNumber == LOGIN) {
            std::string resultStatus = result.get<std::string>("status");

            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->onMessage(response_str);

        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}


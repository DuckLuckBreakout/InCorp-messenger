#include <src/server/lib/Connection/Connection.h>
#include "CommandHandler.h"
#include "src/server/lib/CompanyServer/Server/Server.h"

CommandHandler::CommandHandler() : parser(), mainLogic() {}

void CommandHandler::runRequest(std::shared_ptr<Connection> connection, std::string message) {
    try {

        std::shared_ptr<BaseCommand> command = parser.createCommand(message);

        boost::property_tree::ptree result = mainLogic.executeCommand(command);

        if ((result.get<int>("globalId") > 0) && (Collection::getInstance()->client_collection.find(result.get<int>("globalId")) ==  Collection::getInstance()->client_collection.end())) {
            Collection::getInstance()->client_collection.insert(std::make_pair(result.get<int>("globalId"), connection));
        }


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

        } else if (commandNumber == WRITE_MESSAGE) {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->on_message(response_str);
            for (auto connect : Collection::getInstance()->client_collection) {
                if (connect.second == connection)
                    continue;
                boost::property_tree::ptree pt;
                pt.add("command", "23");
                pt.add("body.chatId", result.get<std::string>("body.chatId"));

                std::stringstream buf;
                boost::property_tree::json_parser::write_json(buf, pt);
                std::string sendNewMessageMessage = buf.str() + "\r\n";

                std::shared_ptr<BaseCommand> sendNewMessage = parser.createCommand(sendNewMessageMessage);
                boost::property_tree::ptree result1 = mainLogic.executeCommand(sendNewMessage);
                result1.put("numRequest", result1.get<int>("body.chatId"));
                result1.put("command", "-2");
                std::stringstream response2;
                boost::property_tree::json_parser::write_json(response2, result1);
                std::string response_str2 = response2.str() + "\r\n";
                connect.second->on_message(response_str2);
            }
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


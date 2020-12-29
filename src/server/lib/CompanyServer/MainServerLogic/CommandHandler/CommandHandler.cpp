#include <src/server/lib/Connection/Connection.h>
#include "CommandHandler.h"
#include "src/server/lib/CompanyServer/Server/Server.h"
#include "src/server/lib/CompanyServer/MainServerLogic/DataBaseConnector/DataBaseConnector.h"

CommandHandler::CommandHandler() : parser(), mainLogic() {}

template <typename T>
std::vector<T> as_vector(boost::property_tree::ptree const& pt, boost::property_tree::ptree::key_type const& key)
{
    std::vector<T> r;
    for (auto& item : pt.get_child(key))
        r.push_back(item.second.get_value<T>());
    return r;
}


void CommandHandler::runRequest(std::shared_ptr<Connection> connection, std::string message) {
    try {

        std::shared_ptr<BaseCommand> command = parser.createCommand(message);

        std::string companyName;
        DataBaseConnector dbConnector(companyName);
        boost::property_tree::ptree logPTree = command->commandParams;
        logPTree.put("text", message);
        logPTree.add("timeSend", std::time(nullptr));
        logPTree.add("operation", command->name);
        dbConnector.logRequest(logPTree);

        boost::property_tree::ptree result = mainLogic.executeCommand(command);
        int commandNumber = result.get<int>("command");

        if ((commandNumber != LOGIN) && (Collection::getInstance()->client_collection.find(result.get<int>("globalId")) ==  Collection::getInstance()->client_collection.end())) {
            Collection::getInstance()->client_collection.insert(std::make_pair(result.get<int>("globalId"), connection));
        }



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
            bool isChecked = false;
            for (auto connect : Collection::getInstance()->client_collection) {
                if (connect.second == connection)
                    continue;

                for (auto &userId : as_vector<int>(result,"chat_members")) {
                    if ((connect.first) != userId)
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
                    result1.add("body.chatAction", "1");
                    if (connect.second->currentChatId == result1.get<int>("body.chatId")) {
                        result1.put("body.isChecked", "true");
                        isChecked = true;
                    }
                    std::stringstream response2;
                    boost::property_tree::json_parser::write_json(response2, result1);
                    std::string response_str2 = response2.str() + "\r\n";
                    connect.second->on_message(response_str2);
                }
            }
            if (isChecked) {
                result.put("numRequest", result.get<int>("body.chatId"));
                result.put("command", "-2");
                result.add("body.chatAction", "2");
                std::stringstream response2;
                boost::property_tree::json_parser::write_json(response2, result);
                std::string response_str2 = response2.str() + "\r\n";

                connection->on_message(response_str2);
            }
        } else if (commandNumber == 22) {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->on_message(response_str);
            connection->currentChatId = result.get<int>("body.chatId");
            bool isChecked = false;
            for (auto connect : Collection::getInstance()->client_collection) {
                if (connect.second == connection)
                    continue;

                for (auto &userId : as_vector<int>(result,"chat_members")) {
                    if ((connect.first) != userId)
                        continue;

                    if (connect.second->currentChatId == result.get<int>("body.chatId")) {

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
                        result1.add("body.chatAction", "2");
                        std::stringstream response2;
                        boost::property_tree::json_parser::write_json(response2, result1);
                        std::string response_str2 = response2.str() + "\r\n";

                        connect.second->on_message(response_str2);
                        isChecked = true;
                    }
                }
            }
            if (isChecked) {
                result.put("numRequest", result.get<int>("body.chatId"));
                result.put("command", "-2");
                result.add("body.chatAction", "2");
                std::stringstream response2;
                boost::property_tree::json_parser::write_json(response2, result);
                std::string response_str2 = response2.str() + "\r\n";

                connection->on_message(response_str2);
            }
        } else if (commandNumber == -1) {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";

            std::vector<int> newChatMembers = as_vector<int>(result, "body.members_list");

            for (auto connect : Collection::getInstance()->client_collection) {
                continue;

                for (auto &userId : newChatMembers) {
                    if ((connect.first) != userId)
                        continue;
                    connect.second->on_message(response_str);

                }
            }

        } else if (commandNumber == -10) {

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


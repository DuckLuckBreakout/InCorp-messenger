#include <src/server/lib/Connection/Connection.h>
#include "CommandHandler.h"
#include "src/server/lib/CompanyServer/Server/Server.h"
#include "src/server/lib/CompanyServer/MainServerLogic/DataBaseConnector/DataBaseConnector.h"

CommandHandler::CommandHandler() : parser(), mainLogic() {}


void CommandHandler::runRequest(const std::shared_ptr<Connection>& connection, std::string &message) {
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

        if ((commandNumber != LOGIN) and
            (ClientsCollection::getInstance()->clientsCollection.find(result.get<int>("globalId")) == \
             ClientsCollection::getInstance()->clientsCollection.end()))
            ClientsCollection::getInstance()->clientsCollection.insert(std::make_pair(result.get<int>("globalId"),
                                                                                         connection));

        if (commandNumber == LOGIN) {
            std::string resultStatus = result.get<std::string>("status");

            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->onMessage(response_str);

        } else if (commandNumber == LOGOUT) {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->onMessage(response_str);

        } else if (commandNumber == WRITE_MESSAGE) {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->onMessage(response_str);
            bool isChecked = false;
            for (auto connect : ClientsCollection::getInstance()->clientsCollection) {
                if (connect.second == connection)
                    continue;

                for (auto &userId : ptreeVectorToStd<int>(result, "chat_members")) {
                    if ((connect.first) != userId)
                        continue;

                    boost::property_tree::ptree messageNoticePtree;
                    messageNoticePtree.add("command", "23");
                    messageNoticePtree.add("body.chatId", result.get<std::string>("body.chatId"));

                    std::stringstream buf;
                    boost::property_tree::json_parser::write_json(buf, messageNoticePtree);
                    std::string newMessageNoticeStr = buf.str() + "\r\n";

                    std::shared_ptr<BaseCommand> sendNewMessage = parser.createCommand(newMessageNoticeStr);
                    boost::property_tree::ptree newMessageNoticeResult = mainLogic.executeCommand(sendNewMessage);
                    newMessageNoticeResult.put("numRequest", newMessageNoticeResult.get<int>("body.chatId"));
                    newMessageNoticeResult.put("command", "-2");
                    newMessageNoticeResult.add("body.chatAction", "1");
                    if (connect.second->currentChatId == newMessageNoticeResult.get<int>("body.chatId")) {
                        newMessageNoticeResult.put("body.isChecked", "true");
                        isChecked = true;
                    }
                    std::stringstream newMessageNoticeResponse;
                    boost::property_tree::json_parser::write_json(newMessageNoticeResponse, newMessageNoticeResult);
                    std::string newMessageNoticeResultStr = newMessageNoticeResponse.str() + "\r\n";
                    connect.second->onMessage(newMessageNoticeResultStr);
                }
            }
            if (isChecked) {
                result.put("numRequest", result.get<int>("body.chatId"));
                result.put("command", "-2");
                result.add("body.chatAction", "2");
                std::stringstream newMessageNoticeResponse;
                boost::property_tree::json_parser::write_json(newMessageNoticeResponse, result);
                std::string newMessageNoticeResultStr = newMessageNoticeResponse.str() + "\r\n";
                connection->onMessage(newMessageNoticeResultStr);
            }
        } else if (commandNumber == CHATMESSAGES) {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string responseStr = response.str() + "\r\n";
            connection->onMessage(responseStr);
            connection->currentChatId = result.get<int>("body.chatId");
            bool isChecked = false;
            for (auto connect : ClientsCollection::getInstance()->clientsCollection) {
                if (connect.second == connection)
                    continue;

                for (auto &userId : ptreeVectorToStd<int>(result, "chat_members")) {
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
                        std::stringstream responsseNotice;
                        boost::property_tree::json_parser::write_json(responsseNotice, result1);
                        std::string responseNoticeStr = responsseNotice.str() + "\r\n";

                        connect.second->onMessage(responseNoticeStr);
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
                std::string responseNoticeStr = response2.str() + "\r\n";

                connection->onMessage(responseNoticeStr);
            }
        } else if (commandNumber == -1) {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string responseStr = response.str() + "\r\n";
            std::vector<int> newChatMembers = ptreeVectorToStd<int>(result, "body.members_list");

        } else if (commandNumber == -10) {

        } else {
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


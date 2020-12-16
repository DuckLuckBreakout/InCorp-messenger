#include "CommandHandler.h"

int count = 0;

CommandHandler::CommandHandler() : parser(), mainLogic() {}

std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void CommandHandler::runRequest(std::shared_ptr<BaseConnection> connection, std::string message) {
    try {
//        std::string str = connection->getRequest();
//        connection->clearReadBuffer();
//        std::string delimiter = "\r\n";
//        std::vector<std::string> v = split (str, delimiter);
//
//        for (auto i : v) {
//            if (i == std::string(""))
//                continue;
        std::shared_ptr<BaseCommand> command = parser.createCommand(message);
//            if (connection->requests.find((command->commandParams).get<int>("command")) != connection->requests.end()) {
//                if (connection->requests[(command->commandParams).get<int>("command")] >= (command->commandParams).get<int>("numRequest")) {
//                    continue;
//                }
//            }

        boost::property_tree::ptree result = mainLogic.executeCommand(command);
        count++;
//            if (count < 2) {
        std::cout << count << std::endl;
        int commandNumber = result.get<int>("command");
        if (commandNumber == LOGIN) {
            std::string resultStatus = result.get<std::string>("status");
//                if (resultStatus.length() == 0)
//                    connection->loginConfirmed = true;
//                else
//                    connection->loginConfirmed = false;

            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->on_message(response_str);

        } else if (commandNumber == LOGOUT) {
//                connection->loginConfirmed = false;

            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->on_message(response_str);
//                connection->sendRequest(response.str() + "\r\n");
        } else {
            std::stringstream response;
            boost::property_tree::json_parser::write_json(response, result);
            std::string response_str = response.str() + "\r\n";
            connection->on_message(response_str);
//                connection->sendRequest(response.str() + "\r\n");
        }
//            connection->send();
//            if (connection->requests.find((command->commandParams).get<int>("command")) != connection->requests.end())
//                connection->requests[result.get<int>("command")] = result.get<int>("numRequest");
//
//            else
//                connection->requests.insert(std::make_pair(result.get<int>("command"), result.get<int>("numRequest")));
//            sleep(1);
    }
//    }
//    }
    catch(...) {
//        std::cerr << "close connection" << std::endl;
        try {
//            connection->disconnect();
        }
        catch (...) {}    }
}


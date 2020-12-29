#include <boost/property_tree/json_parser.hpp>
#include "CommandsManager.h"

boost::property_tree::ptree CommandsManager::command(boost::property_tree::ptree &params) {

    std::string command = params.get<std::string>("body.text");
    command = command.substr(0,command.find('\n'));
    if (command == "create chat") {
        auto command = params.get<std::string>("body.text");
        int titleStart = command.find("title: ") + 7;
        int titleEnd = command.find("\nmembers id:");
        int membersIdStart = command.find("members id:") + 11;
        int membersIdEnd = command.length();

        std::string title = command.substr(titleStart, titleEnd - titleStart);
        std::string membersId = command.substr(membersIdStart, membersIdEnd - membersIdStart);
        params.put("body.title", title);
        params.put("body.members", membersId);
        dbConnector.createChat(params);
        params.put("command", "-1");
        params.add("body.chatAction", "1");
        params.put("numRequest", "1");
        params.put("status", "true");
        params.put("error", "");
    } else if (command == "create notice") {
        params.put("command", "-10");
        std::stringstream stream;
        boost::property_tree::json_parser::write_json(stream, params);
        std::string response_str = stream.str();
        pid_t pid = fork();
        if (pid == 0)
            execl("./notice_maker", "notice_maker", (response_str + "\r\n\a").c_str(), NULL);
    }
    return params;
}
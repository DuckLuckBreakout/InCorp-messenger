#include "CommandCreator.h"


std::shared_ptr<BaseCommand> CommandCreator::createCommand(std::string &message) {

    boost::property_tree::ptree pt;
    std::istringstream is(message);
    boost::property_tree::read_json(is, pt);

    int requestCommand(pt.get<int>("command"));
    std::cout << "command: " << requestCommand << std::endl;
    std::shared_ptr<BaseCommand> command;
    if (requestCommand == LOGIN) {
        std::cout << "login command" << std::endl;
        std::shared_ptr<Login> login(new Login(pt));
        return login;
    }
    else
        std::cout << "unknown command" << std::endl;
}

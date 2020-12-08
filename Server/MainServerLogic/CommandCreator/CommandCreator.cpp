#include "CommandCreator.h"


std::shared_ptr<BaseCommand> CommandCreator::createCommand(std::string message) {
    boost::property_tree::ptree pt;
    std::istringstream is(message);
    boost::property_tree::read_json(is, pt);

    int requestCommand(pt.get<int>("command"));
    requestCommand++;
    std::cout << "command: " << requestCommand << std::endl;
    std::shared_ptr<BaseCommand> command;
    if (requestCommand == LOGIN) {
        std::cout << "login command" << std::endl;
        std::shared_ptr<Login> login(new Login(pt));
        return login;
    } else if (requestCommand == LOGOUT) {
        std::cout << "logout command" << std::endl;
        std::shared_ptr<Logout> logout(new Logout(pt));
        return logout;
    } else if (requestCommand == WRITE_MESSAGE) {
        std::cout << "write message command" << std::endl;
        std::shared_ptr<WriteMessage> writeMessage(new WriteMessage(pt));
        return writeMessage;
    } else if (requestCommand == CREATE_CHAT) {
        std::cout << "create chat command" << std::endl;
        std::shared_ptr<CreateChat> createChat(new CreateChat(pt));
        return createChat;
    } else if (requestCommand == DELETE_CHAT) {
        std::cout << "delete chat command" << std::endl;
        std::shared_ptr<DeleteChat> deleteChat(new DeleteChat(pt));
        return deleteChat;
    } else if (requestCommand == DELETE_USER) {
        std::cout << "delete user command" << std::endl;
        std::shared_ptr<DeleteUser> deleteUser(new DeleteUser(pt));
        return deleteUser;
    } else
        std::cout << "unknown command" << std::endl;
}

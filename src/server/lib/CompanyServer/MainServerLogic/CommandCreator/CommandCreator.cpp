#include "CommandCreator.h"


std::shared_ptr<BaseCommand> CommandCreator::createCommand(std::string message) {
//    std::cout << message << std::endl;

    boost::property_tree::ptree pt;
    std::istringstream is(message);
    boost::property_tree::read_json(is, pt);

    int requestCommand(pt.get<int>("command"));
//    requestCommand++;
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
    } else if (requestCommand == CREATE_USER) {
        std::cout << "create user command" << std::endl;
        std::shared_ptr<CreateUser> createUser(new CreateUser(pt));
        return createUser;
    }  else if (requestCommand == COMMAND1) {
        std::cout << "command 1" << std::endl;
        std::shared_ptr<Command1> command1(new Command1(pt));
        return command1;
    }  else if (requestCommand == COMMAND2) {
        std::cout << "command 2" << std::endl;
        std::shared_ptr<Command2> command2(new Command2(pt));
        return command2;
    }  else if (requestCommand == COMMAND3) {
        std::cout << "command 3" << std::endl;
        std::shared_ptr<Command3> command3(new Command3(pt));
        return command3;
    }  else if (requestCommand == COMMAND4) {
        std::cout << "command 4" << std::endl;
        std::shared_ptr<Command4> command4(new Command4(pt));
        return command4;
    }  else if (requestCommand == COMMAND5) {
        std::cout << "command 5" << std::endl;
        std::shared_ptr<Command5> command5(new Command5(pt));
        return command5;
    }  else if (requestCommand == COMMAND6) {
        std::cout << "command 6" << std::endl;
        std::shared_ptr<Command6> command6(new Command6(pt));
        return command6;
    }  else if (requestCommand == COMMAND7) {
        std::cout << "command 7" << std::endl;
        std::shared_ptr<Command7> command7(new Command7(pt));
        return command7;
    }   else if (requestCommand == COMMAND8) {
        std::cout << "command 8" << std::endl;
        std::shared_ptr<Command8> command8(new Command8(pt));
        return command8;
    } else
        std::cout << "unknown command" << std::endl;
}

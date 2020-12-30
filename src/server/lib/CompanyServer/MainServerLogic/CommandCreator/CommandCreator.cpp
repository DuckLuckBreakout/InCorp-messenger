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
    }  else if (requestCommand == USERCHATSPREVIEW) {
        std::cout << "command 1" << std::endl;
        std::shared_ptr<GetUserChatsPreview> command1(new GetUserChatsPreview(pt));
        return command1;
    }  else if (requestCommand == CHATINFO) {
        std::cout << "command 2" << std::endl;
        std::shared_ptr<GetChatInfo> command2(new GetChatInfo(pt));
        return command2;
    }  else if (requestCommand == CHATMESSAGES) {
        std::cout << "command 3" << std::endl;
        std::shared_ptr<GetChatMessages> command3(new GetChatMessages(pt));
        return command3;
    }  else if (requestCommand == CHATLASTMESSAGE) {
        std::cout << "command 4" << std::endl;
        std::shared_ptr<GetChatLastMessage> command4(new GetChatLastMessage(pt));
        return command4;
    }  else if (requestCommand == MESSAGEAUTHORINFO) {
        std::cout << "command 5" << std::endl;
        std::shared_ptr<GetMessageAuthorInfo> command5(new GetMessageAuthorInfo(pt));
        return command5;
    }  else if (requestCommand == SERVERLOGS) {
        std::cout << "command 6" << std::endl;
        std::shared_ptr<GetServerLogs> command6(new GetServerLogs(pt));
        return command6;
    }  else if (requestCommand == COMPANYCOMMAND) {
        std::cout << "command 7" << std::endl;
        std::shared_ptr<CompanyCommand> command7(new CompanyCommand(pt));
        return command7;
    }   else if (requestCommand == REGISTERUSER) {
        std::cout << "command 8" << std::endl;
        std::shared_ptr<RegisterUser> command8(new RegisterUser(pt));
        return command8;
    } else
        std::cout << "unknown command" << std::endl;
}

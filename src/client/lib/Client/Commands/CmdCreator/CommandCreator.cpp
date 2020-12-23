#include "CommandCreator.h"

std::shared_ptr<BaseCmd> CommandCreator::createCommand(int command, const std::optional<std::string>& error,
                                                       const std::string& body, int numRequest) {
    std::shared_ptr<BaseCmd> createdCommand;

    switch (command) {
        case Commands::LogIn: {
            createdCommand = std::make_shared<AuthorizationCmd>(numRequest, error, body);
            break;
        }
        case Commands::SendMessage: {
            createdCommand = std::make_shared<SendMessageCmd>(numRequest, error, body);
            break;
        }
        case Commands::SystemUpdate: {
            createdCommand = std::make_shared<SystemUpdateCmd>(numRequest, error, body);
            break;
        }
        case Commands::GetListOfChats: {
            createdCommand = std::make_shared<GetListChats>(numRequest, error, body);
            break;
        }
        case Commands::GetSelectChatRoom: {
            createdCommand = std::make_shared<GetChatRoom>(numRequest, error, body);
            break;
        }
        case Commands::GetMessagesInChat: {
            createdCommand = std::make_shared<GetChatMessages>(numRequest, error, body);
            break;
        }
        case Commands::GetLastMessageInChat: {
            createdCommand = std::make_shared<GetLastMessageCmd>(numRequest, error, body);
            break;
        }
        case Commands::GetUserData: {
            createdCommand = std::make_shared<GetUserCmd>(numRequest, error, body);
            break;
        }
        case Commands::ChatObserver: {
            createdCommand = std::make_shared<ChatObserverCmd>(numRequest, error, body);
            break;
        }
        case Commands::GetLog: {
            createdCommand = std::make_shared<GetLogCmd>(numRequest, error, body);
            break;
        }
        case Commands::RegistrationUser: {
            createdCommand = std::make_shared<RegistrationCmd>(numRequest, error, body);
            break;
        }
        default:
            break;
    }

    return createdCommand;
}
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
        case Commands::ChatUpdate: {
            createdCommand = std::make_shared<ChatUpdateCmd>(numRequest, error, body);
            break;
        }
        default:
            break;
    }

    return createdCommand;
}
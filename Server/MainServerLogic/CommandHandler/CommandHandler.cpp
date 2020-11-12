#include "CommandHandler.h"

void CommandHandler::runRequest(std::shared_ptr<BaseConnection> connection) {
    CommandCreator creator = CommandCreator();
    std::shared_ptr<BaseCommand> command = creator.createCommand("command");
    // TODO: shared_ptr<BaseCommand> command = Parse command()
    // TODO: MainLogic.executeCommand(command);
}
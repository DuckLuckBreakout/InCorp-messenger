#include "MainLogic.h"

// FACADE -- MAIN LOGIC
// TODO: executeCommand(shared_ptr<BaseCommand> command)
// TODO: command->execute(Controller);

MainLogic::MainLogic() : controller(new Controller()) {
}

boost::property_tree::ptree MainLogic::executeCommand(std::shared_ptr<BaseCommand> command) {
    return command->execute(controller);
}

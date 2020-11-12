#include "MainLogic.h"

// FACADE -- MAIN LOGIC
// TODO: executeCommand(shared_ptr<BaseCommand> command)
// TODO: command->execute(Controller);

MainLogic::MainLogic() : controller() {

}

void MainLogic::executeCommand(std::shared_ptr<BaseCommand> command) {
    command->execute(controller);
}

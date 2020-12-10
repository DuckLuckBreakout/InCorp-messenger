#include "MainLogic.h"

MainLogic::MainLogic() : controller(new Controller()) {
}

boost::property_tree::ptree MainLogic::executeCommand(std::shared_ptr<BaseCommand> command) {
    return command->execute(controller);
}

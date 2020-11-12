#include "UpdateChats.h"

void UpdateChats::execute(std::shared_ptr<Controller> controller) {
    controller->updateChats();
}
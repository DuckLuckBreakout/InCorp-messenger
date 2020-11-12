#include "WriteMessage.h"

void WriteMessage::execute(std::shared_ptr<Controller> controller) {
    controller->sendMessage("", 0);
}
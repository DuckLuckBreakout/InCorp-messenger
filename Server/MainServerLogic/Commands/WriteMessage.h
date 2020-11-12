#ifndef TP_PPROJECT_WRITEMESSAGE_H
#define TP_PPROJECT_WRITEMESSAGE_H

#include "BaseCommand.h"

class WriteMessage: public BaseCommand {
public:
    ~WriteMessage() override = default;

    void execute(std::shared_ptr<Controller> controller) override;
};

#endif //TP_PPROJECT_WRITEMESSAGE_H

#ifndef TP_PPROJECT_UPDATECHATS_H
#define TP_PPROJECT_UPDATECHATS_H

#include "BaseCommand.h"

class UpdateChats: public BaseCommand {
public:
    ~UpdateChats() override = default;

    void execute(std::shared_ptr<Controller> controller) override;
};


#endif //TP_PPROJECT_UPDATECHATS_H

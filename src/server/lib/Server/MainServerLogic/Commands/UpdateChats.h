#ifndef TP_PPROJECT_UPDATECHATS_H
#define TP_PPROJECT_UPDATECHATS_H

#include "BaseCommand.h"

class UpdateChats: public BaseCommand {
public:
    explicit UpdateChats(boost::property_tree::ptree& params);

    ~UpdateChats() override = default;
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;

private:
};


#endif //TP_PPROJECT_UPDATECHATS_H

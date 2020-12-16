#ifndef APPLICATION_COMMAND2_H
#define APPLICATION_COMMAND2_H

#include "BaseCommand.h"

class Command2: public BaseCommand {
public:
    explicit Command2(boost::property_tree::ptree& params);

    ~Command2() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_COMMAND2_H

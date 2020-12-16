#ifndef APPLICATION_COMMAND4_H
#define APPLICATION_COMMAND4_H

#include "BaseCommand.h"

class Command4: public BaseCommand {
public:
    explicit Command4(boost::property_tree::ptree& params);

    ~Command4() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_COMMAND4_H

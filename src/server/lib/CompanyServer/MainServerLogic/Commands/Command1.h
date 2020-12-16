
#ifndef APPLICATION_COMMAN1_H
#define APPLICATION_COMMAN1_H
#include "BaseCommand.h"

class Command1: public BaseCommand {
public:
    explicit Command1(boost::property_tree::ptree& params);

    ~Command1() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_COMMAN1_H

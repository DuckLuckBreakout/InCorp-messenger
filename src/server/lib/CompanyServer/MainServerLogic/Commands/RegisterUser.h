#ifndef APPLICATION_REGISTERUSER_H
#define APPLICATION_REGISTERUSER_H
#include "BaseCommand.h"

class RegisterUser: public BaseCommand {
public:
    explicit RegisterUser(boost::property_tree::ptree& params);

    ~RegisterUser() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_REGISTERUSER_H

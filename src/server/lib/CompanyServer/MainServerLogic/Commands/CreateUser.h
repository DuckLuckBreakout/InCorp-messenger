#ifndef APPLICATION_CREATEUSER_H
#define APPLICATION_CREATEUSER_H


#include "BaseCommand.h"

class CreateUser: public BaseCommand {
public:
    explicit CreateUser(boost::property_tree::ptree& params);
    ~CreateUser() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};



#endif //APPLICATION_CREATEUSER_H

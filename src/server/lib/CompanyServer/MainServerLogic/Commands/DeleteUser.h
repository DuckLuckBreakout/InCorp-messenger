#ifndef APPLICATION_DELETEUSER_H
#define APPLICATION_DELETEUSER_H

#include "BaseCommand.h"

class DeleteUser: public BaseCommand {
public:
    explicit DeleteUser(boost::property_tree::ptree& params);
    ~DeleteUser() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};



#endif //APPLICATION_DELETEUSER_H

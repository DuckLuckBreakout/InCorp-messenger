
#ifndef APPLICATION_COMMAN1_H
#define APPLICATION_COMMAN1_H
#include "BaseCommand.h"

class GetUserChatsPreview: public BaseCommand {
public:
    explicit GetUserChatsPreview(boost::property_tree::ptree& params);

    ~GetUserChatsPreview() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_COMMAN1_H

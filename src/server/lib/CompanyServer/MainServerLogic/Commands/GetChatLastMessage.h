#ifndef APPLICATION_GETCHATLASTMESSAGE_H
#define APPLICATION_GETCHATLASTMESSAGE_H

#include "BaseCommand.h"

class GetChatLastMessage: public BaseCommand {
public:
    explicit GetChatLastMessage(boost::property_tree::ptree& params);

    ~GetChatLastMessage() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_GETCHATLASTMESSAGE_H

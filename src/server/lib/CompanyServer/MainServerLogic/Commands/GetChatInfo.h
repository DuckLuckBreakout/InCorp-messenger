#ifndef APPLICATION_GETCHATINFO_H
#define APPLICATION_GETCHATINFO_H

#include "BaseCommand.h"

class GetChatInfo: public BaseCommand {
public:
    explicit GetChatInfo(boost::property_tree::ptree& params);

    ~GetChatInfo() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_GETCHATINFO_H

#ifndef APPLICATION_GETMESSAGEAUTHORINFO_H
#define APPLICATION_GETMESSAGEAUTHORINFO_H
#include "BaseCommand.h"

class GetMessageAuthorInfo: public BaseCommand {
public:
    explicit GetMessageAuthorInfo(boost::property_tree::ptree& params);

    ~GetMessageAuthorInfo() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_GETMESSAGEAUTHORINFO_H

#ifndef APPLICATION_GETMESSAGEAUTHORINFO_H
#define APPLICATION_GETMESSAGEAUTHORINFO_H
#include "BaseCommand.h"

/*
 * Get message author information command class
 */
class GetMessageAuthorInfo: public BaseCommand {
public:
    explicit GetMessageAuthorInfo(boost::property_tree::ptree& params);

    ~GetMessageAuthorInfo() override = default;
    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_GETMESSAGEAUTHORINFO_H

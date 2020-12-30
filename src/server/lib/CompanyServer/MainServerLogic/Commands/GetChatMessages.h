#ifndef APPLICATION_GETCHATMESSAGES_H
#define APPLICATION_GETCHATMESSAGES_H
#include "BaseCommand.h"

/*
 * Get chat messages command class
 */
class GetChatMessages: public BaseCommand {
public:
    explicit GetChatMessages(boost::property_tree::ptree& params);

    ~GetChatMessages() override = default;
    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_GETCHATMESSAGES_H

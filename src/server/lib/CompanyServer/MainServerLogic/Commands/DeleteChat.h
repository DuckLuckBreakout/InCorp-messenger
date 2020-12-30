#ifndef APPLICATION_DELETECHAT_H
#define APPLICATION_DELETECHAT_H

#include "BaseCommand.h"

/*
 * Delete chat command class
 */
class DeleteChat: public BaseCommand {
public:
    explicit DeleteChat(boost::property_tree::ptree& params);
    ~DeleteChat() override = default;
    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_DELETECHAT_H

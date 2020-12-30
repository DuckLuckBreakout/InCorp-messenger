#ifndef APPLICATION_CREATECHAT_H
#define APPLICATION_CREATECHAT_H

#include "BaseCommand.h"

/*
 * Create chat command class
 */
class CreateChat: public BaseCommand {
public:
    explicit CreateChat(boost::property_tree::ptree& params);
    ~CreateChat() override = default;
    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_CREATECHAT_H

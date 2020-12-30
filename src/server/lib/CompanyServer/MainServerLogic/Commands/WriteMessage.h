#ifndef TP_PPROJECT_WRITEMESSAGE_H
#define TP_PPROJECT_WRITEMESSAGE_H

#include "BaseCommand.h"

/*
 * Send message command class
 */
class WriteMessage: public BaseCommand {
public:
    explicit WriteMessage(boost::property_tree::ptree& params);
    ~WriteMessage() override = default;
    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //TP_PPROJECT_WRITEMESSAGE_H

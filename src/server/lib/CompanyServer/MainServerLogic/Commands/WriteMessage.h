#ifndef TP_PPROJECT_WRITEMESSAGE_H
#define TP_PPROJECT_WRITEMESSAGE_H

#include "BaseCommand.h"

class WriteMessage: public BaseCommand {
public:
    explicit WriteMessage(boost::property_tree::ptree& params);

    ~WriteMessage() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //TP_PPROJECT_WRITEMESSAGE_H

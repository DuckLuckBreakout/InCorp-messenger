#ifndef APPLICATION_COMPANYCOMMAND_H
#define APPLICATION_COMPANYCOMMAND_H
#include "BaseCommand.h"

/*
 * Company command class
 */
class CompanyCommand: public BaseCommand {
public:
    explicit CompanyCommand(boost::property_tree::ptree& params);
    ~CompanyCommand() override = default;

    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_COMPANYCOMMAND_H

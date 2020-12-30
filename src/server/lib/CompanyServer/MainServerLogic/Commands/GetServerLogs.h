#ifndef APPLICATION_GETSERVERLOGS_H
#define APPLICATION_GETSERVERLOGS_H
#include "BaseCommand.h"

/*
 * Get server logs command class
 */
class GetServerLogs: public BaseCommand {
public:
    explicit GetServerLogs(boost::property_tree::ptree& params);

    ~GetServerLogs() override = default;
    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_GETSERVERLOGS_H

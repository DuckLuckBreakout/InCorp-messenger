//
// Created by Иван Коваленко on 14.12.2020.
//

#ifndef APPLICATION_COMMAND_H
#define APPLICATION_COMMAND_H
#include "BaseCommand.h"

class Command: public BaseCommand {
public:
    explicit Command(boost::property_tree::ptree& params);

    ~Command() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_COMMAND_H

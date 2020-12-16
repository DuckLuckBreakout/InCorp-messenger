//
// Created by Иван Коваленко on 14.12.2020.
//

#ifndef APPLICATION_COMMAND7_H
#define APPLICATION_COMMAND7_H
#include "BaseCommand.h"

class Command7: public BaseCommand {
public:
    explicit Command7(boost::property_tree::ptree& params);

    ~Command7() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_COMMAND7_H

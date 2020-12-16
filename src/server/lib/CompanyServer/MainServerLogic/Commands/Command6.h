//
// Created by Иван Коваленко on 14.12.2020.
//

#ifndef APPLICATION_COMMAND6_H
#define APPLICATION_COMMAND6_H
#include "BaseCommand.h"

class Command6: public BaseCommand {
public:
    explicit Command6(boost::property_tree::ptree& params);

    ~Command6() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_COMMAND6_H

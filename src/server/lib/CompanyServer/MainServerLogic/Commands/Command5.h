//
// Created by Иван Коваленко on 14.12.2020.
//

#ifndef APPLICATION_COMMAND5_H
#define APPLICATION_COMMAND5_H
#include "BaseCommand.h"

class Command5: public BaseCommand {
public:
    explicit Command5(boost::property_tree::ptree& params);

    ~Command5() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_COMMAND5_H

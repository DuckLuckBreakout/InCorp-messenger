//
// Created by Иван Коваленко on 14.12.2020.
//

#ifndef APPLICATION_COMMAND3_H
#define APPLICATION_COMMAND3_H
#include "BaseCommand.h"

class Command3: public BaseCommand {
public:
    explicit Command3(boost::property_tree::ptree& params);

    ~Command3() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_COMMAND3_H

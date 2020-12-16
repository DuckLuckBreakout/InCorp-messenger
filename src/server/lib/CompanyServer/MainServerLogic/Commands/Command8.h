//
// Created by Иван Коваленко on 14.12.2020.
//

#ifndef APPLICATION_COMMAND8_H
#define APPLICATION_COMMAND8_H
#include "BaseCommand.h"

class Command8: public BaseCommand {
public:
    explicit Command8(boost::property_tree::ptree& params);

    ~Command8() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_COMMAND8_H

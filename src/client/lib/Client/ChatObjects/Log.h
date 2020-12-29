#ifndef APPLICATION_LOG_H
#define APPLICATION_LOG_H

#include "BaseObject.h"
#include "KeyWords.h"


class Log : public BaseObject {
public:
    Log();
    ~Log() override = default;

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    std::string text;
    time_t timeSend;
    std::string operation;
    unsigned int number;
};

#endif //APPLICATION_LOG_H

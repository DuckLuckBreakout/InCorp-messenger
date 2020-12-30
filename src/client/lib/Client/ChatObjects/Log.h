#ifndef APPLICATION_LOG_H
#define APPLICATION_LOG_H

#include "BaseObject.h"
#include "KeyWords.h"


// Log of one user command
class Log : public BaseObject {
public:
    Log();
    ~Log() override = default;

	// Get encode string
    std::string encode() const override;

    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    std::string text;
    time_t timeSend;
    std::string operation;
    unsigned int number;
};

#endif //APPLICATION_LOG_H

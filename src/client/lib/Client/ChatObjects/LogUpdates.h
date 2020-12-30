#ifndef APPLICATION_LOGUPDATES_H
#define APPLICATION_LOGUPDATES_H

#include <vector>
#include "BaseObject.h"
#include "Log.h"


// Log updates of all commands
class LogUpdates : public BaseObject {
public:
    LogUpdates();
    LogUpdates(int lastMessageNum, int maxNumMessages);
    ~LogUpdates() override = default;

    // Get encode string
    std::string encode() const override;

    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    int lastMessageNum;
    int maxNumMessages;
    std::vector<Log> logs;
};



#endif //APPLICATION_LOGUPDATES_H

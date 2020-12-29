#ifndef APPLICATION_LOGUPDATES_H
#define APPLICATION_LOGUPDATES_H

#include <vector>
#include "BaseObject.h"
#include "Log.h"


class LogUpdates : public BaseObject {
public:
    LogUpdates();
    LogUpdates(int lastMessageNum, int maxNumMessages);
    ~LogUpdates() override = default;

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int lastMessageNum;
    int maxNumMessages;
    std::vector<Log> logs;
};



#endif //APPLICATION_LOGUPDATES_H

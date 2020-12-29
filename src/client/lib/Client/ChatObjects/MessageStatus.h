#ifndef APPLICATION_MESSAGESTATUS_H
#define APPLICATION_MESSAGESTATUS_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


class MessageStatus : public BaseObject {
public:
    MessageStatus();
    MessageStatus(int chatId);
    ~MessageStatus() override = default;

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
};



#endif //APPLICATION_MESSAGESTATUS_H

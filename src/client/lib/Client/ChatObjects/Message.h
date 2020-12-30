#ifndef APPLICATION_MESSAGE_H
#define APPLICATION_MESSAGE_H

#include "BaseObject.h"
#include "KeyWords.h"


// Message object
class Message : public BaseObject {
public:
    Message();
    Message(int chatId, const std::string& text,
            int idOwner, time_t timeSend, unsigned int number);
    Message(int chatId);
    ~Message() override = default;

    // Get encode string
    std::string encode() const override;

    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
    std::string text;
    int ownerId;
    time_t timeSend;
    bool isChecked;
    unsigned int number;
};


#endif //APPLICATION_MESSAGE_H

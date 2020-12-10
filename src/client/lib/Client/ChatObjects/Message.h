#ifndef APPLICATION_MESSAGE_H
#define APPLICATION_MESSAGE_H

#include "BaseObject.h"
#include "KeyWords.h"


class Message : public BaseObject {
public:
    Message();
    Message(int chatId, const std::string& text,
            int idOwner, time_t timeSend, unsigned int number);

    std::string encode() const override;
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

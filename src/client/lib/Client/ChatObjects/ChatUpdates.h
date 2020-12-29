#ifndef APPLICATION_CHATUPDATES_H
#define APPLICATION_CHATUPDATES_H

#include <vector>
#include "BaseObject.h"
#include "Message.h"


class ChatUpdates : public BaseObject {
public:
    ChatUpdates();
    ChatUpdates(int chatId, int lastMessageNum,
                int maxNumMessages);
    ~ChatUpdates() override = default;

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
    int lastMessageNum;
    int maxNumMessages;
    std::vector<Message> messages;
};


#endif //APPLICATION_CHATUPDATES_H

#ifndef APPLICATION_CHATITEM_H
#define APPLICATION_CHATITEM_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


// Chat item for view chat in chat list
class ChatItem : public BaseObject {
public:
    ChatItem();
    ChatItem(int id, const std::string& chatName);
    ~ChatItem() override = default;

    // Get encode string
    std::string encode() const override;

    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
    std::string chatName;
};


#endif //APPLICATION_CHATITEM_H

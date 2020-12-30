#ifndef APPLICATION_LISTCHAT_H
#define APPLICATION_LISTCHAT_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"
#include "ChatItem.h"


// List of all user chats
class ListChats : public BaseObject {
public:
    ListChats();
    ~ListChats() override = default;

	// Get encode string
    std::string encode() const override;

    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    std::vector<ChatItem> chats;
};


#endif //APPLICATION_LISTCHAT_H

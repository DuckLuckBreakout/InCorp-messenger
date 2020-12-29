#ifndef APPLICATION_LISTCHAT_H
#define APPLICATION_LISTCHAT_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"
#include "ChatItem.h"


class ListChats : public BaseObject {
public:
    ListChats();
    ~ListChats() override = default;

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    std::vector<ChatItem> chats;
};


#endif //APPLICATION_LISTCHAT_H

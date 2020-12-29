#ifndef APPLICATION_CHATITEM_H
#define APPLICATION_CHATITEM_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


class ChatItem : public BaseObject {
public:
    ChatItem();
    ChatItem(int id, const std::string& chatName);
    ~ChatItem() override = default;

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
    std::string chatName;
};


#endif //APPLICATION_CHATITEM_H

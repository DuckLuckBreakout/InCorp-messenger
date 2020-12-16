#ifndef APPLICATION_CHATROOM_H
#define APPLICATION_CHATROOM_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


class ChatRoom : public BaseObject {
public:
    ChatRoom();
    ChatRoom(int id);

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
    std::string chatName;
    std::vector<int> usersId;
};

#endif //APPLICATION_CHATROOM_H

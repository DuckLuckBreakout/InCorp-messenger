#ifndef APPLICATION_CHATROOM_H
#define APPLICATION_CHATROOM_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


// Chat room for select room
class ChatRoom : public BaseObject {
public:
    ChatRoom();
    ChatRoom(int id);
    ~ChatRoom() override = default;

	// Get encode string
    std::string encode() const override;
    
    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
    std::string chatName;
    std::vector<int> usersId;
};

#endif //APPLICATION_CHATROOM_H

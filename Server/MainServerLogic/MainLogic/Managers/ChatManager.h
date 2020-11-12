#ifndef SERVER_CHATMANAGER_H
#define SERVER_CHATMANAGER_H

#include "BaseManager.h"
#include "../../../../src/libs/Connection/BaseConnection.h"

class ChatManager: public BaseManager {
public:
    ~ChatManager() override = default;

    void sendMessage(std::string message, int chatID);
    void updateChats();
    void deleteChat(int chatID);
    void createChat();
};

#endif //SERVER_CHATMANAGER_H

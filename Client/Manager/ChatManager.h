#ifndef TP_PPROJECT_CHATMANAGER_H
#define TP_PPROJECT_CHATMANAGER_H

#include <memory>

#include "BaseManager.h"
#include "src/libs/Connection/BaseConnection.h"

class ChatManager : public BaseManager {
public:
    ~ChatManager() override = default;

    void sendMessage(std::shared_ptr<BaseConnection>& connection,
                     int chatId, const std::string& message);

    void updateChats(std::shared_ptr<BaseConnection>& connection);
    void createChat(std::shared_ptr<BaseConnection>& connection,
                    const std::string& chatName);

};


#endif

#ifndef TP_PPROJECT_MANAGEROPTIONS_H
#define TP_PPROJECT_MANAGEROPTIONS_H

#include <iostream>

#include "src/libs/Connection/BaseConnection.h"
#include "BaseUserOptions.h"

class ManagerOptions : public BaseUserOptions {
public:
    ~ManagerOptions() override = default;

    void login(std::shared_ptr<BaseConnection>& connection,
               const std::string& token) override;
    void logout(std::shared_ptr<BaseConnection>& connection) override;
    void sendMessage(std::shared_ptr<BaseConnection>& connection,
                     int chatId, const std::string& message) override;
    void updateChats(std::shared_ptr<BaseConnection>& connection) override;
    void createChat(std::shared_ptr<BaseConnection>& connection,
                    const std::string& chatName) override;
};


#endif

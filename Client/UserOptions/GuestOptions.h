#ifndef TP_PPROJECT_GUESTOPTIONS_H
#define TP_PPROJECT_GUESTOPTIONS_H

#include <iostream>
#include <memory>



#include "src/libs/Connection/BaseConnection.h"
#include "src/libs/Connection/HttpConnection.h"
#include "BaseUserOptions.h"

class GuestOptions : public BaseUserOptions {
public:
    ~GuestOptions() override = default;

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

#ifndef TP_PPROJECT_CLIENT_H
#define TP_PPROJECT_CLIENT_H

#include <thread>
#include <memory>
#include <boost/asio.hpp>

#include "BaseClient.h"

class Client : public BaseClient {
public:
    Client();
    ~Client() override = default;

    void login(const std::string& token) override;
    void logout() override;
    void sendMessage(int chatId, const std::string& message) override;
    void updateChats() override;
    void createChat(const std::string& chatName) override;
    void setRole(const std::string& role) override;

    void startClient() override;


private:
    void run();
    void startConnect();
    void handlerConnect(const boost::system::error_code &error);
    void listen();
    void restart();
};


#endif

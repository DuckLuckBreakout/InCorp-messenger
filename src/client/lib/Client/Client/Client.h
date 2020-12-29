#ifndef TP_PPROJECT_CLIENT_H
#define TP_PPROJECT_CLIENT_H

#include <thread>
#include <memory>
#include <boost/asio.hpp>

#include "BaseClient.h"


class Client : public BaseClient, public std::enable_shared_from_this<Client> {
public:
    Client();
    Client(const Client& client) = delete;
    Client(Client&& client) = delete;
    Client& operator= (const Client& client) = delete;
    Client& operator= (Client&& client) = delete;
    ~Client() override = default;

    void sendMessage(const std::string& message) override;

    void setMessageHandler(const std::function<void(const std::string&)>& handler) override;
    void setErrorHandler(const std::function<void(int)>& handler) override;

    std::optional<std::function<void(int)>> getErrorHandler() override;

    void startClient(const std::string& ip, const std::string& port) override;
    void endClient() override;

private:
    void connect(boost::asio::ip::tcp::resolver::iterator& it);

    void handleConnect(const boost::system::error_code& error);
    void handleError(const boost::system::error_code& error);
    void loop();
    void sendAllMessagesFromQueue();
};


#endif //TP_PPROJECT_CLIENT_H

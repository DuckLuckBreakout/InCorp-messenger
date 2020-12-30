#ifndef TP_PPROJECT_CLIENT_H
#define TP_PPROJECT_CLIENT_H

#include <thread>
#include <memory>
#include <boost/asio.hpp>

#include "BaseClient.h"


// Client for connection with server 
class Client : public BaseClient, public std::enable_shared_from_this<Client> {
public:
    Client();
    Client(const Client& client) = delete;
    Client(Client&& client) = delete;
    Client& operator= (const Client& client) = delete;
    Client& operator= (Client&& client) = delete;
    ~Client() override = default;

    // Send string to server
    void sendMessage(const std::string& message) override;

    // Set message handler for answer from server
    void setMessageHandler(const std::function<void(const std::string&)>& handler) override;
    
    // Set error handler for answer from server
    void setErrorHandler(const std::function<void(int)>& handler) override;
    // Get error handler
    std::optional<std::function<void(int)>> getErrorHandler() override;

    // Start client
    void startClient(const std::string& ip, const std::string& port) override;
    // End client
    void endClient() override;

private:
    void connect(boost::asio::ip::tcp::resolver::iterator& it);

    void handleConnect(const boost::system::error_code& error);
    void handleError(const boost::system::error_code& error);
    void loop();
    void sendAllMessagesFromQueue();
};


#endif //TP_PPROJECT_CLIENT_H

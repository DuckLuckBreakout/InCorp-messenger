#ifndef TP_PPROJECT_BASECLIENT_H
#define TP_PPROJECT_BASECLIENT_H

#include <utility>
#include <iostream>
#include <memory>
#include <queue>
#include <boost/bind.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <thread>
#include <boost/asio/streambuf.hpp>


// Abstract Client for connection 
class BaseClient {
public:
    BaseClient()
            : service(), socket(service),
            iterator(), readBuffer(), thread(), messages() {}

    virtual ~BaseClient() = default;

    // Send string to server
    virtual void sendMessage(const std::string& message) = 0;
    
    // Set message handler for answer from server
    virtual void setMessageHandler(const std::function<void(const std::string&)>& func) = 0;
    
    // Set error handler for answer from server
    virtual void setErrorHandler(const std::function<void(int)>& func) = 0;
    // Get error handler
    virtual std::optional<std::function<void(int)>> getErrorHandler() = 0;

    // Start client
    virtual void startClient(const std::string& ip, const std::string& port) = 0;
    // End client
    virtual void endClient() = 0;

protected:
    boost::asio::io_service service;
    boost::asio::ip::tcp::socket socket;

    boost::asio::ip::tcp::resolver::iterator iterator;
    std::optional<std::function<void(const std::string &)>> messageHandler;
    std::optional<std::function<void(int)>> errorHandler;
    boost::asio::streambuf readBuffer;
    std::thread thread;
    std::deque<std::string> messages;
};


#endif //TP_PPROJECT_BASECLIENT_H

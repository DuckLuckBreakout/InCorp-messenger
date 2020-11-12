#ifndef TP_PPROJECT_BASECONNECTION_H
#define TP_PPROJECT_BASECONNECTION_H

#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "../Connection/Coder/BaseCoder.h"

class BaseConnection {
public:
    BaseConnection(boost::asio::io_service &service) : socket(service) {}
    virtual ~BaseConnection() = default;

    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void sendRequest(std::string request) = 0;
    virtual std::string getRequest() = 0;

    virtual boost::asio::ip::tcp::socket& getSocket() = 0;
    virtual void send() = 0;
    virtual void read() = 0;

protected:
    boost::asio::ip::tcp::socket socket;
    std::string readBuff = "hello";
    std::string sendBuff = "hello";
};


#endif

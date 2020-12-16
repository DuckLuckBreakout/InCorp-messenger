#ifndef TP_PPROJECT_BASESERVER_H
#define TP_PPROJECT_BASESERVER_H


#include <thread>
#include <iostream>
#include <functional>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "src/server/lib/CompanyServer/MainServerLogic/CommandHandler/CommandHandler.h"
#include "src/server/lib/Connection/BaseConnection.h"


class BaseServer {
public:
    BaseServer() : acceptor(service) {}
    virtual ~BaseServer() = default;
    virtual void startServer(int port) = 0;

public:
    virtual void onAccept(std::shared_ptr<BaseConnection> client,
                          const boost::system::error_code& error) = 0;
    virtual void startAccept() = 0;
    virtual void run() = 0;
    virtual void runTask(std::shared_ptr<BaseConnection> client) = 0;
    virtual void restart(std::shared_ptr<BaseConnection> client) = 0;

protected:
    boost::asio::io_service service;
    boost::asio::ip::tcp::acceptor acceptor;
};

#endif //TP_PPROJECT_BASESERVER_H

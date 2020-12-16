#ifndef SERVER_HTTPSERVER_H
#define SERVER_HTTPSERVER_H

#include "src/server/lib/CompanyServer/MainServerLogic/CommandHandler/CommandHandler.h"
#include "src/server/lib/Connection/Connection.h"
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

class Collection {
public:
    static std::shared_ptr<Collection> getInstance();
    std::map<int, std::shared_ptr<Connection>> client_collection;
private:
    Collection() : client_collection() {};
};

using namespace boost::asio;

using boost::asio::ip::tcp;

class Server: public std::enable_shared_from_this<Server>  {
public:
    explicit Server(boost::asio::io_service& io_service);
    Server(boost::asio::io_service& io_service,
           boost::asio::io_service::strand& strand,
           const tcp::endpoint& endpoint);
    ~Server() = default;

private:
    void run();
    void on_accept(std::shared_ptr<Connection> connection, const boost::system::error_code& error);
    boost::asio::io_service &io_service;
    tcp::acceptor acceptor;
    boost::asio::io_service::strand& strand;
//    std::shared_ptr<std::map<int, std::shared_ptr<Connection>>> connections;
};
#endif //SERVER_HTTPSERVER_H

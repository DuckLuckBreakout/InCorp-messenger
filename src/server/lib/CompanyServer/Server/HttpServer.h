#ifndef SERVER_HTTPSERVER_H
#define SERVER_HTTPSERVER_H


#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "src/server/lib/Connection/HttpConnection.h"

using namespace boost::asio;

using boost::asio::ip::tcp;

class HttpServer: public std::enable_shared_from_this<HttpServer>  {
public:
    explicit HttpServer(boost::asio::io_service& io_service);
    HttpServer(boost::asio::io_service& io_service,
               boost::asio::io_service::strand& strand,
               const tcp::endpoint& endpoint);
    ~HttpServer() = default;
    typedef std::shared_ptr<HttpServer> ptr;

private:

    void run();
    void on_accept(std::shared_ptr<HttpConnection> new_abstract_Connection, const boost::system::error_code& error);

    boost::asio::io_service &io_service;
    tcp::acceptor acceptor;
    boost::asio::io_service::strand& strand;
    std::map<int, std::shared_ptr<BaseConnection>> client_collection;
};
#endif //SERVER_HTTPSERVER_H

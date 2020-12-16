#ifndef TP_PPROJECT_HTTPCONNECTION_H
#define TP_PPROJECT_HTTPCONNECTION_H

#include <boost/bind.hpp>
#include <include/boost/asio/io_service.hpp>
#include <include/boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include "BaseConnection.h"


class Connection : public BaseConnection,
                   public std::enable_shared_from_this<Connection> {
public:
    Connection(boost::asio::io_service& io_service,
               boost::asio::io_service::strand& strand) :
            socket_(io_service),
            strand(strand) {}
    void read_handler(const boost::system::error_code& error, size_t bytes_transferred);

public:
    boost::asio::ip::tcp::socket &socket();
    void on_message(std::string &msg);
private:
    void write_handler(const boost::system::error_code& error);

private:
    boost::asio::ip::tcp::socket socket_;
    boost::asio::io_service::strand& strand;
    boost::asio::streambuf read_msg;
    std::deque<std::string> write_msgs;
};

#endif

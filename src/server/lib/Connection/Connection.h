#ifndef TP_PPROJECT_HTTPCONNECTION_H
#define TP_PPROJECT_HTTPCONNECTION_H

#include <boost/bind.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include "BaseConnection.h"

/*
 * Connection class
 */
class Connection : public BaseConnection,
                   public std::enable_shared_from_this<Connection> {
public:
    Connection(boost::asio::io_service& io_service,
               boost::asio::io_service::strand& strand) :
            socket_(io_service),
            strand(strand) {}
    void readHandler(const boost::system::error_code& error, size_t bytes_transferred);

    int currentChatId = -1;
    boost::asio::ip::tcp::socket &socket();

    /*
     * Sending a response to the client
     */
    void onMessage(std::string &msg);
private:
    void writeHandler(const boost::system::error_code& error);

private:
    boost::asio::ip::tcp::socket socket_;
    boost::asio::io_service::strand& strand;
    boost::asio::streambuf readMsg;
    std::deque<std::string> writeMsgs;
};

#endif

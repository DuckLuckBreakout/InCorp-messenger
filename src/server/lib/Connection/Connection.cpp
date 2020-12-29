#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "Connection.h"
#include "src/server/lib/CompanyServer/MainServerLogic/CommandHandler/CommandHandler.h"


using boost::asio::ip::tcp;

boost::asio::ip::tcp::socket &Connection::socket() {
    return socket_;
}

void Connection::onMessage(std::string &msg) {
    bool writeInProgress = not writeMsgs.empty();
    writeMsgs.push_back(msg);
    if (not writeInProgress) {
        std::cout << "Send message (on message): " << writeMsgs.front() << std::endl;
        boost::asio::async_write(socket_,
                                 boost::asio::buffer(writeMsgs.front(), writeMsgs.front().size()),
                                 strand.wrap(boost::bind(&Connection::writeHandler, shared_from_this(), _1)));
    }
}


void Connection::read_handler(const boost::system::error_code& error, size_t bytes_transferred) {
    if (not error) {
        if (not this) {
            return;
        }

        if (bytes_transferred > 0) {
            std::string str{buffers_begin(readMsg.data()),
                            buffers_begin(readMsg.data()) + bytes_transferred - 2};
            readMsg.consume(bytes_transferred);
            std::cout << "Read message: " << str << std::endl;

            CommandHandler handler;
            handler.runRequest(shared_from_this(), str);
        }

        boost::asio::async_read_until(socket_, readMsg, "\r\n",
                                      strand.wrap(boost::bind(&Connection::read_handler, shared_from_this(), _1, boost::asio::placeholders::bytes_transferred)));
    }
}

void Connection::writeHandler(const boost::system::error_code &error) {
    if (not error) {

        std::cout << "Send message: " << writeMsgs.front() << std::endl;
        writeMsgs.pop_front();

        if (not writeMsgs.empty())
        {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(writeMsgs.front(), writeMsgs.front().size()),
                                     strand.wrap(boost::bind(&Connection::writeHandler, shared_from_this(), _1)));
        }
    }
}


#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include "HttpConnection.h"
#include "src/server/lib/CompanyServer/MainServerLogic/CommandHandler/CommandHandler.h"



using boost::asio::ip::tcp;

boost::asio::ip::tcp::socket &HttpConnection::socket() {
    return socket_;
}

void HttpConnection::on_message(std::string &msg) {
    bool write_in_progress = !write_msgs.empty();
    write_msgs.push_back(msg);
    if (!write_in_progress) {
        std::cout << "Send message (on message): " << write_msgs.front() << std::endl;
        boost::asio::async_write(socket_,
                                 boost::asio::buffer(write_msgs.front(), write_msgs.front().size()),
                                 strand.wrap(boost::bind(&HttpConnection::write_handler, shared_from_this(), _1)));
    }
}


void HttpConnection::read_handler(const boost::system::error_code &error, size_t bytes_transferred) {
    if (!error) {
        if (!this) {
            return;
        }

        if (bytes_transferred > 0) {
            std::string str{buffers_begin(read_msg.data()),
                            buffers_begin(read_msg.data()) + bytes_transferred - 2};
            read_msg.consume(bytes_transferred);
            std::cout << "Read message: " << str << std::endl;

            CommandHandler handler;
            handler.runRequest(shared_from_this(), str);
        }

        boost::asio::async_read_until(socket_, read_msg, "\r\n",
                                      strand.wrap(boost::bind(&HttpConnection::read_handler, shared_from_this(), _1, boost::asio::placeholders::bytes_transferred)));
    }
}

void HttpConnection::write_handler(const boost::system::error_code &error) {
    if (!error) {

        std::cout << "Send message: " << write_msgs.front() << std::endl;
        write_msgs.pop_front();

        if (!write_msgs.empty())
        {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(write_msgs.front(), write_msgs.front().size()),
                                     strand.wrap(boost::bind(&HttpConnection::write_handler, shared_from_this(), _1)));
        }
    }
}


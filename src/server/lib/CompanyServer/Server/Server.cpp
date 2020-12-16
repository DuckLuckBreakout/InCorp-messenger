#include "Server.h"
#include "src/server/lib/Connection/HttpConnection.h"
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <thread>
#include <mutex>

Server::Server(boost::asio::io_service& io_service,
               boost::asio::io_service::strand& strand,
               const tcp::endpoint& endpoint) :
        io_service(io_service),
        strand(strand),
        acceptor(io_service, endpoint) {

    run();
}

void Server::run() {
    std::shared_ptr<HttpConnection> new_abstract_Connection(new HttpConnection(io_service, strand));
    acceptor.async_accept(new_abstract_Connection->socket(),
                          strand.wrap(boost::bind(&Server::on_accept,
                                                  this,
                                                  new_abstract_Connection,
                                                  _1)));
}

void Server::on_accept(std::shared_ptr<HttpConnection> new_abstract_Connection, const boost::system::error_code& error) {
    new_abstract_Connection->read_handler(error, 0);
    run();
}
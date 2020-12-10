#include "HttpServer.h"

HttpServer::HttpServer() : BaseServer() {}

void HttpServer::startServer(int port) {
    mongocxx::instance instance{};

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);

    acceptor.open(endpoint.protocol());
    acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor.bind(endpoint);
    acceptor.listen(1024);
    startAccept();

    std::vector<std::thread> threads;
    int countCPU = sysconf(_SC_NPROCESSORS_ONLN);
    for (int i = 0; i < countCPU; i++)
        threads.push_back(std::thread([this] { run(); }));

    for (auto& thread : threads)
        thread.join();
}

void HttpServer::onAccept(std::shared_ptr<BaseConnection> client, const boost::system::error_code& error) {
    if (error)
        return;

    std::cerr << "Start read client: " << client->getSocket().remote_endpoint().address().to_string().c_str()
              << std::endl;

    service.post([this, client] { runTask(client); });

    startAccept();
}

void HttpServer::runTask(std::shared_ptr<BaseConnection> client) {
    try {

        boost::asio::io_service::strand strandOne(service);
        read(strandOne, client);
        //    if (client->getRequest()[0]) {
        // service.post(strandOne.wrap([client] { client->read(); }));

        std::shared_ptr<CommandHandler> commandHendler(new CommandHandler());
        service.post(strandOne.wrap([commandHendler, client] { commandHendler->runRequest(client); }));

        // service.post(strandOne.wrap([client] { client->send(); }));
        send(strandOne, client);
        //    }
        service.post(strandOne.wrap([this, client] { restart(client); }));
    }
    catch(...) {
        std::cerr << "lalala" << std::endl;
    }
}

void HttpServer::startAccept() {
    std::shared_ptr<HttpConnection> client = std::make_shared<HttpConnection>(service);
    acceptor.async_accept(client->getSocket(), boost::bind(&HttpServer::onAccept, this, client,
                                                           boost::asio::placeholders::error));
}

void HttpServer::run() {
    service.run();
}

void HttpServer::restart(std::shared_ptr<BaseConnection> client) {
    runTask(client);
}

void HttpServer::read(boost::asio::io_service::strand &strandOne, std::shared_ptr<BaseConnection> client) {
    try {
    service.post(strandOne.wrap([client] { client->read(); }));
    }
    catch(...) {
    std::cerr << "lalala" << std::endl;
    }
}

void HttpServer::send(boost::asio::io_service::strand &strandOne, std::shared_ptr<BaseConnection> client) {
    service.post(strandOne.wrap([client] { client->send(); }));
}



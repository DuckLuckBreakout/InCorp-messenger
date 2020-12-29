#ifndef SERVER_HTTPSERVER_H
#define SERVER_HTTPSERVER_H


#include "BaseServer.h"
#include "Server/MainServerLogic/CommandHandler/CommandHandler.h"
#include "src/libs/Connection/HttpConnection.h"


class Server: public BaseServer {
public:
    Server();
    ~Server() override = default;

    void startServer(int port) override;
    void read(boost::asio::io_service::strand &strandOne, std::shared_ptr<BaseConnection> client);
    void send(boost::asio::io_service::strand &strandOne, std::shared_ptr<BaseConnection> client);

public:
    void onAccept(std::shared_ptr<BaseConnection> client,
                  const boost::system::error_code& error) override;
    void startAccept() override;
    void run() override;
    void runTask(std::shared_ptr<BaseConnection> client) override;
    void restart(std::shared_ptr<BaseConnection> client) override;

};


#endif //SERVER_HTTPSERVER_H

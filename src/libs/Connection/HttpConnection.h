#ifndef TP_PPROJECT_HTTPCONNECTION_H
#define TP_PPROJECT_HTTPCONNECTION_H

#include <boost/bind.hpp>

#include "BaseConnection.h"
#include "src/libs/Connection/Coder/HttpCoder.h"

class HttpConnection : public BaseConnection {
public:
    HttpConnection(boost::asio::io_service& service);
    ~HttpConnection() override;

    void connect() override;
    void disconnect() override;
    void sendRequest(std::string request) override;
    std::string getRequest() override;

    boost::asio::ip::tcp::socket& getSocket() override;
    void send() override;
    void read() override;

private:
    std::shared_ptr<HttpCoder> coder;
};


#endif

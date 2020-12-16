#include "HttpConnection.h"

HttpConnection::HttpConnection(boost::asio::io_service &service) : BaseConnection(service) {}

HttpConnection::~HttpConnection() = default;

void HttpConnection::connect() {

}

void HttpConnection::disconnect() {

}

void HttpConnection::sendRequest(std::string request) {
    sendBuff = request;
}

std::string HttpConnection::getRequest() {
    return readBuff;
}

boost::asio::ip::tcp::socket & HttpConnection::getSocket() {
    return socket;
}

void HttpConnection::read() {
    try {
        sendBuff.clear();
        std::cerr << "input : " << std::endl;
        std::cerr << "thread is " << pthread_self() << std::endl;
        int n = socket.read_some(boost::asio::buffer(readBuff));
        std::cerr << "was read message: [ " << n << " ] ";
        std::cerr << "http: " << readBuff << "\n";
    }


//    std::cerr << "decoding: " << coder->decode(readBuff) << "\n";
    catch(...) {
        std::cerr << "close connection" << std::endl;
    }
}

void HttpConnection::send() {
    for (int i = 0; i < 1024; i++) {
        readBuff[i] = '\0';
    }
    std::cerr << "send: " << std::endl;
    std::cerr << "thread is " << pthread_self() << std::endl;
    int n = socket.write_some(boost::asio::buffer(sendBuff));
    std::cerr << "was send message: [ " << n << " ] ";

    std::cerr << "was read message: [ " << n << " ] ";
    std::cerr << "simple: " << sendBuff << "\n";
//    std::cerr << "encoding: " << coder->encode(sendBuff) << "\n";
}

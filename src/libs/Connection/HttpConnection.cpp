#include "HttpConnection.h"

HttpConnection::HttpConnection(boost::asio::io_service &service) : BaseConnection(service) {}

HttpConnection::~HttpConnection() = default;

void HttpConnection::connect() {

}

void HttpConnection::disconnect() {

}

void HttpConnection::sendRequest(std::string request) {

}

std::string HttpConnection::getRequest() {

}

boost::asio::ip::tcp::socket & HttpConnection::getSocket() {
    return socket;
}

void HttpConnection::read() {
//    readBuff.clear();

    std::cerr << "input : " << std::endl;
    std::cerr << "thread is " << pthread_self() << std::endl;
    int n = socket.read_some(boost::asio::buffer(readBuff));

    std::cerr << "was read message: [ " << n << " ] ";
    std::cerr << "http: " << readBuff << "\n";
//    std::cerr << "decoding: " << coder->decode(readBuff) << "\n";
}

void HttpConnection::send() {
    std::cerr << "send: " << std::endl;
    std::cerr << "thread is " << pthread_self() << std::endl;
    int n = socket.write_some(boost::asio::buffer(sendBuff));
    std::cerr << "was send message: [ " << n << " ] ";

    std::cerr << "was read message: [ " << n << " ] ";
    std::cerr << "simple: " << sendBuff << "\n";
//    std::cerr << "encoding: " << coder->encode(sendBuff) << "\n";
}

#include "Client.h"


Client::Client() : BaseClient() {}

void Client::sendMessage(const std::string &message) {
    service.post([self = shared_from_this(), message]() -> void {
        bool isEmpty = self->messages.empty();
        self->messages.push_back(message + "\r\n");
        if (isEmpty)
            self->sendAllMessagesFromQueue();
    });
}

void Client::sendAllMessagesFromQueue() {
    boost::asio::async_write(socket,
boost::asio::buffer(messages.front().data(),messages.front().size()),
    [self = shared_from_this()](boost::system::error_code error,
                             std::size_t length) -> void {
        if (error)
            self->handleError(error);
        else {
            std::cerr << "was send: \n" << self->messages.front() << std::endl;

            self->messages.pop_front();
            if (!self->messages.empty()) {

                self->sendAllMessagesFromQueue();
            }
        }
    });
}

void Client::setMessageHandler(const std::function<void(const std::string &)>& handler) {
    messageHandler = handler;
}

void Client::setErrorHandler(const std::function<void(int)>& handler) {
    errorHandler = handler;
}

void Client::handleConnect(const boost::system::error_code &error) {
    if (error)
        handleError(error);
    else
        loop();
}

void Client::loop() {
    boost::asio::async_read_until(socket, readBuffer, "\r\n",
        [self = shared_from_this()](boost::system::error_code error,
              size_t length) -> void {
            if (error)
                self->handleError(error);
            else {

                std::cerr << "[ " + std::to_string(length) + " ] " << std::endl;
                if (length > 0) {
                    std::string str{buffers_begin(self->readBuffer.data()),
                                    buffers_begin(self->readBuffer.data()) + length - 2};
                    self->readBuffer.consume(length);
                    std::cerr << "Read message: " << str << std::endl;
                    if (self->messageHandler) {
                        self->messageHandler.value()(str);
                    } 
                    else {
                        self->endClient();
                        throw std::runtime_error(error.message());
                    }
                }
                self->loop();
            }
    });
}

void Client::handleError(const boost::system::error_code &error) {
    if (!error)
        errorHandler.value()(error.value());
    else {
        endClient();
        throw std::runtime_error(error.message());
    }
}

void Client::endClient() {
    service.post([self = shared_from_this()]() {
        self->socket.close();
    });
}

void Client::connect(boost::asio::ip::tcp::resolver::iterator &iterator) {
    boost::asio::async_connect(socket, iterator,
                               boost::bind(&Client::handleConnect, shared_from_this(),
                                                  boost::asio::placeholders::error));
}

void Client::startClient(const std::string& ip, const std::string& port) {
    boost::asio::ip::tcp::resolver resolver(service);
    std::pair<std::string, std::string> host(ip, port);
    std::optional opt(host);

    iterator = resolver.resolve({opt.value().first, opt.value().second});
    connect(iterator);
    thread = std::thread([self = shared_from_this()]() -> void {
        self->service.run();
    });
}

std::optional<std::function<void(int)>> Client::getErrorHandler() {
    return errorHandler;
}

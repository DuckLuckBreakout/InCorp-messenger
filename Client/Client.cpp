#include "Client.h"


Client::Client() : BaseClient() {
    userOptions = std::make_shared<EmployeeOptions>();
    roleController = std::make_shared<RoleController>();
}

// Run request to login on server
void Client::login(const std::string& token) {
    service.post(strand.wrap([this, token]
                                    { userOptions->login(connection, token); }));
}


// Run request to logout on server
void Client::logout() {
    service.post(strand.wrap([this]
                                    { userOptions->logout(connection); }));
}


// Run request to write message in chat on server
void Client::sendMessage(int chatId, const std::string& message) {
    service.post(strand.wrap([this, chatId, message]
                                    { userOptions->sendMessage(connection, chatId, message); }));
}


// Run request to update all chats
void Client::updateChats() {
    service.post(strand.wrap([this]
                                    { userOptions->updateChats(connection); }));
}


// Run request to create chat
void Client::createChat(const std::string& chatName) {
    service.post(strand.wrap([this, chatName]
                                    { userOptions->createChat(connection, chatName); }));
}


// Run request to set role of user
void Client::setRole(const std::string& role) {
    service.post(strand.wrap([this, role]
                                    { roleController->setRole(userOptions, role); }));
}


// Run client and wait main function of application
void Client::startClient() {
    endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),
                                              5000);

    startConnect();

    std::vector<std::thread> threads;
    int countCPU = sysconf(_SC_NPROCESSORS_ONLN);
    for (int i = 0; i < countCPU; i++)
        threads.push_back(std::thread([this] { run(); }));

    for (auto& thread : threads)
        thread.join();
}

// Handler connection
void Client::handlerConnect(const boost::system::error_code &error) {
    if (error)
        return;

    service.post([this] { listen(); });
}

// Start connect
void Client::startConnect() {
    connection = std::make_shared<HttpConnection>(service);
    connection->getSocket().async_connect(endpoint, boost::bind(&Client::handlerConnect, this,
                                                        boost::asio::placeholders::error));
}

// Listen update chats from server
void Client::listen() {
    service.post(strand.wrap([this] { updateChats(); }));
    service.post(strand.wrap([this] { restart(); }));
}

// Loop for listen updates
void Client::restart() {
    sleep(10);
    listen();
}

// Run async tasks
void Client::run() {
    service.run();
}
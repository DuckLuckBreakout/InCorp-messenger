#include "Controller.h"

std::shared_ptr<Controller> Controller::getInstance() {
    static std::shared_ptr<Controller> controller(new Controller);
    return controller;
}

Controller::Controller() {
    client = std::make_shared<Client>();
    callbackHolder = std::make_shared<CallbacksHolder>();
    userOptions = std::make_shared<GuestOptions>();
}

void Controller::runClient(const std::string& ip, const std::string& port,
                           const std::function<void(int)>& errHandler) {
    std::cerr << "Connect to " << ip << " " << port << std::endl;
    client->setErrorHandler(errHandler);
    client->startClient(ip, port);
    client->setMessageHandler(boost::bind(&Controller::readMessageHandler,
                                          shared_from_this(), _1));
}

void Controller::reconnectClient(const std::string& ip, const std::string& port) {
    std::optional<std::function<void(int)>> errorHandler = client->getErrorHandler();
    client = std::make_shared<Client>();
    runClient(ip, port, errorHandler.value());
}

void Controller::sendMessage(const Message& message,  int globalId,
                             const std::shared_ptr<BaseCallback>& callback) {
    userOptions->sendMessage(message, globalId, callback, client, callbackHolder);
}

void Controller::authorization(const UserInfo& authInfo, int globalId,
                               const std::shared_ptr<BaseCallback>& callback) {
    userOptions->authorization(authInfo, globalId, callback, client, callbackHolder);
}

void Controller::chatUpdate(const ChatUpdates &chatUpdates, int globalId,
                            const std::shared_ptr<BaseCallback>& callback) {
    userOptions->chatUpdate(chatUpdates, globalId, callback, client, callbackHolder);
}

void Controller::getListChats(const ListChats &listChats, int globalId,
                              const std::shared_ptr<BaseCallback> &callback) {
    userOptions->getListChats(listChats, globalId, callback, client, callbackHolder);
}

void Controller::getChatRoom(const ChatRoom& chatRoom, int globalId,
                             const std::shared_ptr<BaseCallback> &callback) {
    userOptions->getChatRoom(chatRoom, globalId, callback, client, callbackHolder);
}

void Controller::getChatMessages(const ChatUpdates &chatUpdates, int globalId,
                                 const std::shared_ptr<BaseCallback> &callback) {
    userOptions->getChatMessages(chatUpdates, globalId, callback, client, callbackHolder);
}

void Controller::getLastMessage(const Message &message, int globalId,
                                const std::shared_ptr<BaseCallback> &callback) {
    userOptions->getLastMessage(message, globalId, callback, client, callbackHolder);
}

void Controller::getUser(const UserPreview &user, int globalId,
                         const std::shared_ptr<BaseCallback> &callback) {
    userOptions->getUser(user, globalId, callback, client, callbackHolder);
}

void Controller::setChatObserver(int chatId, const std::shared_ptr<BaseCallback> &callback) {
    userOptions->setChatObserver(chatId, callback, client, callbackHolder);
}

void Controller::getLog(const LogUpdates& logUpdates, int globalId,
                        const std::shared_ptr<BaseCallback> &callback) {
    userOptions->getLog(logUpdates, globalId, callback, client, callbackHolder);
}

void Controller::sendChatCommand(const Message &message, int globalId) {
    userOptions->sendChatCommand(message, globalId, client, callbackHolder);
}

void Controller::registration(const UserInfo& authInfo, int globalId,
                              const std::shared_ptr<BaseCallback>& callback) {
    userOptions->registration(authInfo, globalId, callback, client, callbackHolder);
}


void Controller::readMessageHandler(const std::string& str) {
    Request query;

    try {
        query.decode(str);
    }
    catch(...) {
        throw std::runtime_error("Can't decode answer from server!");
    }

    std::optional<std::string> error;
    if (!query.status)
        error = query.error;

    if ((query.command == Commands::LogIn) && (query.status)) {
        UserInfo account;
        account.decode(query.body);
        RoleController::setRole(userOptions, account.role);
    }

    std::shared_ptr<BaseCmd> command = CommandCreator::createCommand(query.command, error,
                                                                     query.body, query.numRequest);
    command->execute(callbackHolder);
}
















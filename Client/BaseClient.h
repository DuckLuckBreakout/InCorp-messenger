#ifndef TP_PPROJECT_BASECLIENT_H
#define TP_PPROJECT_BASECLIENT_H

#include <utility>
#include <iostream>
#include <memory>
#include <boost/bind.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "src/libs/Connection/BaseConnection.h"
#include "src/libs/Connection/HttpConnection.h"
#include "Manager/ChatManager.h"
#include "Manager/AuthorizationManager.h"
#include "RoleController/BaseRoleController.h"
#include "UserOptions/BaseUserOptions.h"
#include "RoleController/RoleController.h"

class BaseClient {
public:
    BaseClient() : strand(service) {}
    virtual ~BaseClient() = default;

    virtual void login(const std::string& token) = 0;
    virtual void logout() = 0;
    virtual void sendMessage(int chatId, const std::string& message) = 0;
    virtual void updateChats() = 0;
    virtual void createChat(const std::string& chatName) = 0;
    virtual void setRole(const std::string& role) = 0;

    virtual void startClient() = 0;

protected:
    std::shared_ptr<BaseRoleController> roleController;
    std::shared_ptr<BaseUserOptions> userOptions;
    boost::asio::io_service service;
    boost::asio::ip::tcp::endpoint endpoint;
    boost::asio::io_service::strand strand;
    std::shared_ptr<BaseConnection> connection;
};

#endif

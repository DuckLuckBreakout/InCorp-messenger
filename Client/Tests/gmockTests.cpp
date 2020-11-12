#include <gmock/gmock.h>

#include "Client/Manager/AuthorizationManager.h"
#include "Client/RoleController/RoleController.h"
#include "Client/Client.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

// Test Client
class MockClient : public Client {
public:
    MOCK_METHOD1(login, void(const std::string& token));
    MOCK_METHOD0(logout, void());
    MOCK_METHOD2(sendMessage, void(int chatId, const std::string& message));
    MOCK_METHOD0(updateChats, void());
    MOCK_METHOD1(createChat, void(const std::string& chatName));
    MOCK_METHOD1(setRole, void(const std::string& role));
    MOCK_METHOD0(startClient, void());
};

TEST(Client, CanLogout) {
    MockClient client;
    EXPECT_CALL(client, logout()).Times(AtLeast(1));
    client.logout();
}

TEST(Client, CanLogin) {
    MockClient client;
    EXPECT_CALL(client, login("test_token")).Times(AtLeast(1));
    client.login("test_token");
}

TEST(Client, CanSendMessage) {
    MockClient client;
    EXPECT_CALL(client, sendMessage(1, "test_message")).Times(AtLeast(1));
    client.sendMessage(1, "test_message");
}

TEST(Client, CanUpdateChats) {
    MockClient client;
    EXPECT_CALL(client, updateChats()).Times(AtLeast(1));
    client.updateChats();
}

TEST(Client, CanCreateChat) {
    MockClient client;
    EXPECT_CALL(client, createChat("new_chat")).Times(AtLeast(1));
    client.createChat("new_chat");
}

TEST(Client, CanSetRole) {
    MockClient client;
    EXPECT_CALL(client, setRole("employee")).Times(AtLeast(1));
    client.setRole("employee");
}

TEST(Client, CanStartClient) {
    MockClient client;
    EXPECT_CALL(client, startClient()).Times(AtLeast(1));
    client.startClient();
}

// Test RoleController
class MockController : public RoleController {
public:
    MOCK_METHOD2(setRole, void(std::shared_ptr<BaseUserOptions>& userOptions,
                               const std::string& role));
};

TEST(RoleController, CanSetRole) {
    MockController controller;
    std::shared_ptr<BaseUserOptions> options = std::make_shared<GuestOptions>();
    EXPECT_CALL(controller, setRole(options, "guest")).Times(AtLeast(1));
    controller.setRole(options, "guest");
}

// Test Guest Options
class MockGuestOptions : public GuestOptions {
public:
    MOCK_METHOD2(login, void(std::shared_ptr<BaseConnection>& connection,
                             const std::string& token));
};

TEST(GuestOptions, CanLogin) {
    MockGuestOptions options;
    boost::asio::io_service service;
    std::shared_ptr<BaseConnection> connection = std::make_shared<HttpConnection>(service);

    EXPECT_CALL(options, login(connection, "test_token")).Times(AtLeast(1));
    options.login(connection, "test_token");
}


// Test Employee Options
class MockEmployeeOptions : public EmployeeOptions {
public:
    MOCK_METHOD1(logout, void(std::shared_ptr<BaseConnection>& connection));
    MOCK_METHOD3(sendMessage, void(std::shared_ptr<BaseConnection>& connection,
                                   int chatId, const std::string& message));
    MOCK_METHOD1(updateChats, void(std::shared_ptr<BaseConnection>& connection));
    MOCK_METHOD2(createChat, void(std::shared_ptr<BaseConnection>& connection,
                                  const std::string& chatName));
};

TEST(EmployeeOptions, CanLogout) {
    MockEmployeeOptions options;
    boost::asio::io_service service;
    std::shared_ptr<BaseConnection> connection = std::make_shared<HttpConnection>(service);

    EXPECT_CALL(options, logout(connection)).Times(AtLeast(1));
    options.logout(connection);
}

TEST(EmployeeOptions, CanSendMessage) {
    MockEmployeeOptions options;
    boost::asio::io_service service;
    std::shared_ptr<BaseConnection> connection = std::make_shared<HttpConnection>(service);

    EXPECT_CALL(options, sendMessage(connection, 1, "test_message")).Times(AtLeast(1));
    options.sendMessage(connection, 1, "test_message");
}

TEST(EmployeeOptions, CanUpdateChats) {
    MockEmployeeOptions options;
    boost::asio::io_service service;
    std::shared_ptr<BaseConnection> connection = std::make_shared<HttpConnection>(service);

    EXPECT_CALL(options, updateChats(connection)).Times(AtLeast(1));
    options.updateChats(connection);
}


// Test Manager Options
class MockManagerOptions : public EmployeeOptions {
public:
    MOCK_METHOD1(logout, void(std::shared_ptr<BaseConnection>& connection));
    MOCK_METHOD3(sendMessage, void(std::shared_ptr<BaseConnection>& connection,
            int chatId, const std::string& message));
    MOCK_METHOD1(updateChats, void(std::shared_ptr<BaseConnection>& connection));
    MOCK_METHOD2(createChat, void(std::shared_ptr<BaseConnection>& connection,
            const std::string& chatName));
};

TEST(ManagerOptions, CanLogout) {
    MockManagerOptions options;
    boost::asio::io_service service;
    std::shared_ptr<BaseConnection> connection = std::make_shared<HttpConnection>(service);

    EXPECT_CALL(options, logout(connection)).Times(AtLeast(1));
    options.logout(connection);
}

TEST(ManagerOptions, CanSendMessage) {
    MockManagerOptions options;
    boost::asio::io_service service;
    std::shared_ptr<BaseConnection> connection = std::make_shared<HttpConnection>(service);

    EXPECT_CALL(options, sendMessage(connection, 1, "test_message")).Times(AtLeast(1));
    options.sendMessage(connection, 1, "test_message");
}

TEST(ManagerOptions, CanUpdateChats) {
    MockManagerOptions options;
    boost::asio::io_service service;
    std::shared_ptr<BaseConnection> connection = std::make_shared<HttpConnection>(service);

    EXPECT_CALL(options, updateChats(connection)).Times(AtLeast(1));
    options.updateChats(connection);
}

TEST(ManagerOptions, CanCreateChat) {
    MockManagerOptions options;
    boost::asio::io_service service;
    std::shared_ptr<BaseConnection> connection = std::make_shared<HttpConnection>(service);

    EXPECT_CALL(options, createChat(connection, "new_chat")).Times(AtLeast(1));
    options.createChat(connection, "new_chat");
}
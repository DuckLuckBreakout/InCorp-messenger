#include <gmock/gmock.h>


#include "Server/Server/HttpServer.h"
#include "Server/MainServerLogic/CommandCreator/CommandCreator.h"
#include "Server/MainServerLogic/Commands/Login.h"
#include "Server/MainServerLogic/Commands/Logout.h"
#include "Server/MainServerLogic/Commands/UpdateChats.h"
#include "Server/MainServerLogic/Commands/WriteMessage.h"
#include "Server/MainServerLogic/MainLogic/Controller/Controller.h"
#include "Server/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"
#include "Server/MainServerLogic/MainLogic/Managers/ChatManager.h"
#include "Server/MainServerLogic/MainLogic/MainLogic.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

class MockServer : public HttpServer {
public:

    MOCK_METHOD1(startServer, void (int port));
    MOCK_METHOD2(read, void(boost::asio::io_service::strand &strandOne, std::shared_ptr<BaseConnection> client));
    MOCK_METHOD2(send, void(boost::asio::io_service::strand &strandOne, std::shared_ptr<BaseConnection> client));
public:
    MOCK_METHOD2(onAccept, void(std::shared_ptr<BaseConnection> client,
            const boost::system::error_code& error));
    MOCK_METHOD0(startAccept, void ());
    MOCK_METHOD0(run, void ());
    MOCK_METHOD1(runTask, void(std::shared_ptr<BaseConnection> client));
    MOCK_METHOD1(restart, void(std::shared_ptr<BaseConnection> client));
};

TEST(Server, startServer) {
    MockServer server;
    EXPECT_CALL(server, startServer(5000)).Times(AtLeast(1));
    server.startServer(5000);
}

TEST(Server, startAccept) {
    MockServer server;
    EXPECT_CALL(server, startAccept()).Times(AtLeast(1));
    server.startAccept();
}

TEST(Server, run) {
    MockServer server;
    EXPECT_CALL(server, run()).Times(AtLeast(1));
    server.run();
}

class MockCommandCreator : public CommandCreator {
public:
    MOCK_METHOD1(createCommand, std::shared_ptr<BaseCommand>(std::string message));
};

class MockLogin : public Login {
public:
    MOCK_METHOD1(execute, void(std::shared_ptr<Controller> controller));
};

TEST(Login, execute) {
    MockLogin login;
    std::shared_ptr<Controller> controller;
    EXPECT_CALL(login, execute(controller)).Times(AtLeast(1));
    login.execute(controller);
}

class MockLogout : public Logout {
public:
    MOCK_METHOD1(execute, void(std::shared_ptr<Controller> controller));
};

TEST(Logout, execute) {
    MockLogout logout;
    std::shared_ptr<Controller> controller;
    EXPECT_CALL(logout, execute(controller)).Times(AtLeast(1));
    logout.execute(controller);
}

class MockUpdateChats : public UpdateChats {
public:
    MOCK_METHOD1(execute, void(std::shared_ptr<Controller> controller));
};

TEST(UpdateChats, execute) {
    MockUpdateChats updateChats;
    std::shared_ptr<Controller> controller;
    EXPECT_CALL(updateChats, execute(controller)).Times(AtLeast(1));
    updateChats.execute(controller);
}

class MockWriteMessage : public WriteMessage {
public:
    MOCK_METHOD1(execute, void(std::shared_ptr<Controller> controller));
};

TEST(WriteMessage, execute) {
    MockWriteMessage writeMessage;
    std::shared_ptr<Controller> controller;
    EXPECT_CALL(writeMessage, execute(controller)).Times(AtLeast(1));
    writeMessage.execute(controller);
}

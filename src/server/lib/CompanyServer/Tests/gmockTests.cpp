#include <gmock/gmock.h>


#include "src_/Server/Server/HttpServer.h"
#include "src_/Server/MainServerLogic/CommandCreator/CommandCreator.h"
#include "src_/Server/MainServerLogic/Commands/Login.h"
#include "src_/Server/MainServerLogic/Commands/Logout.h"
#include "src_/Server/MainServerLogic/Commands/UpdateChats.h"
#include "src_/Server/MainServerLogic/Commands/WriteMessage.h"
#include "src_/Server/MainServerLogic/MainLogic/Controller/Controller.h"
#include "src_/Server/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"
#include "src_/Server/MainServerLogic/MainLogic/Managers/ChatManager.h"
#include "src_/Server/MainServerLogic/MainLogic/MainLogic.h"
#include "src_/Server/MainServerLogic/DataBaseConnector/DataBaseConnector.h"

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

//class MockCommandCreator : public CommandCreator {
//public:
//    MOCK_METHOD1(createCommand, std::shared_ptr<BaseCommand>(std::string message));
//};


//class MockLogin : public Login {
//public:
//    MOCK_METHOD1(execute, boost::property_tree::ptree(std::shared_ptr<Controller> controller));
//};

TEST(Login, execute_bad_login) {
    boost::property_tree::ptree params;
    params.add("command", "0");
    params.add("body.login", "test");
    params.add("body.password", "test");
    Login login(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = login.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("command", "0");
    realResult.add("body.login", "test");
    realResult.add("body.password", "test");
    realResult.add("status", "false");
    realResult.add("error", "Not registered");
    EXPECT_EQ(result == realResult, true);
}

TEST(Login, execute_good_login) {
    boost::property_tree::ptree params;
    params.add("command", "0");
    params.add("body.login", "newUser");
    params.add("body.password", "pas123");
    Login login(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = login.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("command", "0");
    realResult.add("body.login", "newUser");
    realResult.add("body.password", "pas123");
    realResult.add("body.userId", "1");
    realResult.add("body.chatsId", "[1, 2, 3]");
    realResult.add("body.firstName", "Ivan");
    realResult.add("body.lastName", "Kovalenko");
    realResult.add("body.role", "employee");
    realResult.add("status", "true");
    realResult.add("error", "");
    EXPECT_EQ(result == realResult, true);
}


TEST(Logout, execute_bad_login) {
    boost::property_tree::ptree params;
    params.add("body.login", "test123");
    Logout logout(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = logout.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("body.login", "test123");
    realResult.add("error", "User not login");
    realResult.add("status", "false");

    EXPECT_EQ(result == realResult, true);
}

TEST(Logout, execute_good_login) {
    boost::property_tree::ptree params;
    params.add("body.login", "newUser");
    Logout logout(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = logout.execute(controller);


    boost::property_tree::ptree realResult;
    realResult.add("body.login", "newUser");
    realResult.add("status", "true");
    realResult.add("error", "");
    EXPECT_EQ(result == realResult, true);
}


TEST(CreateUser, execute_bad_login) {
    boost::property_tree::ptree params;
    params.add("command", "0");
    params.add("body.login", "newUser");
    params.add("body.password", "test");
    CreateUser createUser(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = createUser.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("command", "0");
    realResult.add("body.login", "newUser");
    realResult.add("body.password", "test");
    realResult.add("error", "User already registered");
    realResult.add("status", "true");

    EXPECT_EQ(result == realResult, true);
}

TEST(CreateUser, execute_good_login) {
    boost::property_tree::ptree params;
    params.add("command", "0");
    params.add("body.login", "realNewUser");
    params.add("body.password", "pas123");
    CreateUser createUser(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = createUser.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("command", "0");
    realResult.add("body.login", "realNewUser");
    realResult.add("body.password", "pas123");
    realResult.add("status", "true");
    realResult.add("error", "");

    EXPECT_EQ(result == realResult, true);
}

TEST(DeleteUser, execute_bad_login) {
    boost::property_tree::ptree params;
    params.add("body.login", "newUserRawra");
    DeleteUser deleteUser(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = deleteUser.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("body.login", "newUserRawra");
    realResult.add("error", "User not registered");
    realResult.add("status", "false");

    EXPECT_EQ(result == realResult, true);
}

TEST(DeleteUser, execute_good_login) {
    boost::property_tree::ptree params;
    params.add("body.login", "realNewUser");
    DeleteUser deleteUser(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = deleteUser.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("body.login", "realNewUser");
    realResult.add("status", "true");
    realResult.add("error", "");


    EXPECT_EQ(result == realResult, true);
}

TEST(CreateChat, execute_good_id) {
    boost::property_tree::ptree params;
    params.add("body.chatId", "-1");
    CreateChat createChat(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = createChat.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("body.chatId", "-1");
    realResult.add("status", "true");
    realResult.add("error", "");

    EXPECT_EQ(result == realResult, true);
}

TEST(DeleteChat, execute_good_id) {
    boost::property_tree::ptree params;
    params.add("body.chatId", "-1");
    DeleteChat deleteChat(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = deleteChat.execute(controller);

    boost::property_tree::ptree realResult;
    realResult.add("body.chatId", "-1");
    realResult.add("status", "true");
    realResult.add("error", "");

    EXPECT_EQ(result == realResult, true);
}

TEST(WriteMessage, execute_good_id) {
    boost::property_tree::ptree params;
    params.add("body.chatId", "0");
    params.add("body.text", "lalala");
    WriteMessage writeMessage(params);
    std::shared_ptr<Controller> controller(new Controller);
    boost::property_tree::ptree result = writeMessage.execute(controller);


    boost::property_tree::ptree realResult;
    realResult.add("body.chatId", "0");
    realResult.add("body.text", "lalala");
    realResult.add("body.isChecked", "false");
    realResult.add("status", "true");
    realResult.add("error", "");

    EXPECT_EQ(result == realResult, true);
}


TEST(DataBaseConnector, userIsRegistered) {
    DataBaseConnector dbConnector("test_company");
    EXPECT_EQ(true == dbConnector.userIsRegistered("newUser"), true);
    EXPECT_EQ(false == dbConnector.userIsRegistered("newUser124124"), true);
}

TEST(DataBaseConnector, authorizeUser) {
    DataBaseConnector dbConnector("test_company");
    dbConnector.authorizeUser("test_user");
}

TEST(DataBaseConnector, logoutUser) {
    DataBaseConnector dbConnector("test_company");
    dbConnector.logoutUser("41244214");
}

TEST(DataBaseConnector, userIsAuthorized) {
    DataBaseConnector dbConnector("test_company");
    EXPECT_EQ(true == dbConnector.userIsAuthorized("test_user"), true);
    EXPECT_EQ(false == dbConnector.userIsAuthorized("newUser124124"), true);
}

TEST(DataBaseConnector, addMessage) {
    DataBaseConnector dbConnector("test_company");
    boost::property_tree::ptree params;
    params.add("body.chatId", "0");
    params.add("body.text", "lalala");
    dbConnector.addMessage(params);
}

TEST(DataBaseConnector, createChat) {
    DataBaseConnector dbConnector("test_company");
    boost::property_tree::ptree params;
    params.add("body.chatId", "0");
    dbConnector.createChat(params);
}

TEST(DataBaseConnector, deleteChat) {
    DataBaseConnector dbConnector("test_company");
    boost::property_tree::ptree params;
    params.add("body.chatId", "124");
    dbConnector.deleteChat(params);
}

TEST(DataBaseConnector, deleteUser) {
    DataBaseConnector dbConnector("test_company");
    boost::property_tree::ptree params;
    params.add("body.login", "124fasf");
    dbConnector.deleteUser(params);
}

TEST(DataBaseConnector, createUser) {
    DataBaseConnector dbConnector("test_company");
    boost::property_tree::ptree params;
    params.add("body.login", "124fasf");
    dbConnector.createUser(params);
}

TEST(DataBaseConnector, getUserInfo) {
    DataBaseConnector dbConnector("test_company");

    boost::property_tree::ptree params;
    params.add("body.login", "newUser");
    params.add("body.password", "pas123");

    dbConnector.getUserInfo(params);

    EXPECT_EQ(
    (params.get<std::string>("body.login") == "newUser") && \
    (params.get<std::string>("body.password") == "pas123") && \
    (params.get<std::string>("body.userId") == "1") && \
    (params.get<std::string>("body.chatsId") == "[1, 2, 3]") && \
    (params.get<std::string>("body.firstName") == "Ivan") && \
    (params.get<std::string>("body.lastName") == "Kovalenko") && \
    (params.get<std::string>("body.role") == "employee"), true);
}


//    boost::property_tree::ptree params;
//    params.add("body.chatId", "0");
//    params.add("body.text", "lalala");
//    WriteMessage writeMessage(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = writeMessage.execute(controller);
//
//
//    boost::property_tree::ptree realResult;
//    realResult.add("body.chatId", "0");
//    realResult.add("body.text", "lalala");
//    realResult.add("body.isChecked", "false");
//    realResult.add("status", "true");
//    realResult.add("error", "");
//
//    EXPECT_EQ(result == realResult, true);

//TEST(DeleteUser, execute_good_login) {
//    boost::property_tree::ptree params;
//    params.add("body.login", "realNewUser");
//    DeleteUser deleteUser(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = deleteUser.execute(controller);
//
//    boost::property_tree::ptree realResult;
//    realResult.add("body.login", "realNewUser");
//    realResult.add("status", "true");
//    realResult.add("error", "");
//
//
//    EXPECT_EQ(result == realResult, true);
//}


//
//class MockLogout : public Logout {
//public:
//    MOCK_METHOD1(execute, void(std::shared_ptr<Controller> controller));
//};
//
//TEST(Logout, execute) {
//    MockLogout logout;
//    std::shared_ptr<Controller> controller;
//    EXPECT_CALL(logout, execute(controller)).Times(AtLeast(1));
//    logout.execute(controller);
//}
//
//class MockUpdateChats : public UpdateChats {
//public:
//    MOCK_METHOD1(execute, void(std::shared_ptr<Controller> controller));
//};
//
//TEST(UpdateChats, execute) {
//    MockUpdateChats updateChats;
//    std::shared_ptr<Controller> controller;
//    EXPECT_CALL(updateChats, execute(controller)).Times(AtLeast(1));
//    updateChats.execute(controller);
//}
//
//class MockWriteMessage : public WriteMessage {
//public:
//    MOCK_METHOD1(execute, void(std::shared_ptr<Controller> controller));
//};
//
//TEST(WriteMessage, execute) {
//    MockWriteMessage writeMessage;
//    std::shared_ptr<Controller> controller;
//    EXPECT_CALL(writeMessage, execute(controller)).Times(AtLeast(1));
//    writeMessage.execute(controller);
//}

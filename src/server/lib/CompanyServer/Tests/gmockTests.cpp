#include <gmock/gmock.h>


#include "src/server/lib/CompanyServer/Server/Server.h"
#include "src/server/lib/CompanyServer/MainServerLogic/CommandCreator/CommandCreator.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Login.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Logout.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/UpdateChats.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/WriteMessage.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Controller/Controller.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/ChatManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/MainLogic.h"
#include "src/server/lib/CompanyServer/MainServerLogic/DataBaseConnector/DataBaseConnector.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;


class MockDataBaseConnector : public DataBaseConnector {
public:
    MOCK_METHOD1(userIsRegistered, bool(std::string &token));
    MOCK_METHOD1(userIsAuthorized, bool(std::string &token));
    MOCK_METHOD1(authorizeUser, void(std::string &token));
    MOCK_METHOD1(logoutUser, void(std::string &token));
    MOCK_METHOD1(addMessage, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(createChat, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(deleteChat, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(createUser, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(deleteUser, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(getUserInfo, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(getChatInfo, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(logRequest, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(getMessageAuthorInfo, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(getUserChatsPreview, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(getChatMessages, void(boost::property_tree::ptree &params));
    MOCK_METHOD1(getUserChats, std::vector<int>(int userId));
    MOCK_METHOD1(getTeamName, std::string(int chatId));
    MOCK_METHOD1(getChatMessagesCount, int(int chatId));
    MOCK_METHOD1(getChatMembers, boost::property_tree::ptree(int chatId));
    MOCK_METHOD1(getChatLastMessage, boost::property_tree::ptree(int chatId));
};


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

    std::stringstream newMessageNoticeResponse;
    boost::property_tree::json_parser::write_json(newMessageNoticeResponse, result);
    std::string newMessageNoticeResultStr = newMessageNoticeResponse.str() + "\r\n";

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


//TEST(Logout, execute_bad_login) {
//    boost::property_tree::ptree params;
//    params.add("body.login", "test123");
//    Logout logout(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = logout.execute(controller);
//
//    boost::property_tree::ptree realResult;
//    realResult.add("body.login", "test123");
//    realResult.add("error", "User not login");
//    realResult.add("status", "false");
//
//    EXPECT_EQ(result == realResult, true);
//}
//
//TEST(Logout, execute_good_login) {
//    boost::property_tree::ptree params;
//    params.add("body.login", "newUser");
//    Logout logout(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = logout.execute(controller);
//
//
//
//    boost::property_tree::ptree realResult;
//    realResult.add("body.login", "newUser");
//    realResult.add("status", "true");
//    realResult.add("error", "");
//    EXPECT_EQ(result == realResult, true);
//}
//
//
//TEST(CreateUser, execute_bad_login) {
//    boost::property_tree::ptree params;
//    params.add("command", "0");
//    params.add("body.login", "newUser");
//    params.add("body.password", "test");
//    CreateUser createUser(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = createUser.execute(controller);
//
//    boost::property_tree::ptree realResult;
//    realResult.add("command", "0");
//    realResult.add("body.login", "newUser");
//    realResult.add("body.password", "test");
//    realResult.add("error", "User already registered");
//    realResult.add("status", "true");
//
//    EXPECT_EQ(result == realResult, true);
//}
//
//TEST(CreateUser, execute_good_login) {
//    boost::property_tree::ptree params;
//    params.add("command", "0");
//    params.add("body.login", "realNewUser");
//    params.add("body.password", "pas123");
//    CreateUser createUser(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = createUser.execute(controller);
//
//    boost::property_tree::ptree realResult;
//    realResult.add("command", "0");
//    realResult.add("body.login", "realNewUser");
//    realResult.add("body.password", "pas123");
//    realResult.add("status", "true");
//    realResult.add("error", "");
//
//    EXPECT_EQ(result == realResult, true);
//}
//
//TEST(DeleteUser, execute_bad_login) {
//    boost::property_tree::ptree params;
//    params.add("body.login", "newUserRawra");
//    DeleteUser deleteUser(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = deleteUser.execute(controller);
//
//    boost::property_tree::ptree realResult;
//    realResult.add("body.login", "newUserRawra");
//    realResult.add("error", "User not registered");
//    realResult.add("status", "false");
//
//    EXPECT_EQ(result == realResult, true);
//}
//
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
//TEST(CreateChat, execute_good_id) {
//    boost::property_tree::ptree params;
//    params.add("body.chatId", "-1");
//    CreateChat createChat(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = createChat.execute(controller);
//
//    boost::property_tree::ptree realResult;
//    realResult.add("body.chatId", "-1");
//    realResult.add("status", "true");
//    realResult.add("error", "");
//
//
//
//    EXPECT_EQ(result == realResult, true);
//}
//
//TEST(DeleteChat, execute_good_id) {
//    boost::property_tree::ptree params;
//    params.add("body.chatId", "-1");
//    DeleteChat deleteChat(params);
//    std::shared_ptr<Controller> controller(new Controller);
//    boost::property_tree::ptree result = deleteChat.execute(controller);
//
//    boost::property_tree::ptree realResult;
//    realResult.add("body.chatId", "-1");
//    realResult.add("status", "true");
//    realResult.add("error", "");
//
//    EXPECT_EQ(result == realResult, true);
//}
//
//TEST(WriteMessage, execute_good_id) {
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
//}
//
//
//TEST(DataBaseConnector, userIsRegistered) {
//    std::string company("test_company");
//    DataBaseConnector dbConnector(company);
//    std::string user("newUser");
//    EXPECT_EQ(true == dbConnector.userIsRegistered(user), true);
//    user = "newUser124124";
//    EXPECT_EQ(false == dbConnector.userIsRegistered(user), true);
//}
//
//TEST(DataBaseConnector, authorizeUser) {
//    std::string company("test_company");
//    DataBaseConnector dbConnector(company);
//    std::string user("test_user");
//    dbConnector.authorizeUser(user);
//}
//
//TEST(DataBaseConnector, logoutUser) {
//    std::string company("test_company");
//
//    DataBaseConnector dbConnector(company);
//    std::string user("test_user");
//    dbConnector.logoutUser(user);
//}
//
//TEST(DataBaseConnector, userIsAuthorized) {
//    std::string company("test_company");
//
//    DataBaseConnector dbConnector(company);
//
//    std::string user("newUser");
//    EXPECT_EQ(true == dbConnector.userIsAuthorized(user), true);
//    user = "newUser124124";
//    EXPECT_EQ(false == dbConnector.userIsAuthorized(user), true);
//}
//
//TEST(DataBaseConnector, addMessage) {
//    std::string company("test_company");
//
//    DataBaseConnector dbConnector(company);
//    boost::property_tree::ptree params;
//    params.add("body.chatId", "0");
//    params.add("body.text", "lalala");
//    dbConnector.addMessage(params);
//}
//
//TEST(DataBaseConnector, createChat) {
//    std::string company("test_company");
//
//    DataBaseConnector dbConnector(company);
//    boost::property_tree::ptree params;
//    params.add("body.chatId", "0");
//    dbConnector.createChat(params);
//}
//
//TEST(DataBaseConnector, deleteChat) {
//    std::string company("test_company");
//
//    DataBaseConnector dbConnector(company);
//    boost::property_tree::ptree params;
//    params.add("body.chatId", "124");
//    dbConnector.deleteChat(params);
//}
//
//TEST(DataBaseConnector, deleteUser) {
//    std::string company("test_company");
//
//    DataBaseConnector dbConnector(company);
//    boost::property_tree::ptree params;
//    params.add("body.login", "124fasf");
//    dbConnector.deleteUser(params);
//}
//
//TEST(DataBaseConnector, createUser) {
//    std::string company("test_company");
//
//    DataBaseConnector dbConnector(company);
//    boost::property_tree::ptree params;
//    params.add("body.login", "124fasf");
//    dbConnector.createUser(params);
//}
//
//TEST(DataBaseConnector, getUserInfo) {
//    std::string company("test_company");
//
//    DataBaseConnector dbConnector(company);
//
//    boost::property_tree::ptree params;
//    params.add("body.login", "newUser");
//    params.add("body.password", "pas123");
//
//    dbConnector.getUserInfo(params);
//
//    EXPECT_EQ(
//    (params.get<std::string>("body.login") == "newUser") && \
//    (params.get<std::string>("body.password") == "pas123") && \
//    (params.get<std::string>("body.userId") == "1") && \
//    (params.get<std::string>("body.chatsId") == "[1, 2, 3]") && \
//    (params.get<std::string>("body.firstName") == "Ivan") && \
//    (params.get<std::string>("body.lastName") == "Kovalenko") && \
//    (params.get<std::string>("body.role") == "employee"), true);
//}

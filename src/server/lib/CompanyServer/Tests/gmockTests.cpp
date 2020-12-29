#include <gmock/gmock.h>

#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Controller/Controller.h"
#include "src/server/lib/CompanyServer/Server/Server.h"
#include "src/server/lib/CompanyServer/MainServerLogic/CommandCreator/CommandCreator.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Login.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Logout.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/UpdateChats.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/WriteMessage.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Controller/Controller.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/AuthorizationManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/ChatManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/CommandsManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/InfoManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/LogsManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/Managers/RegistrationManager.h"
#include "src/server/lib/CompanyServer/MainServerLogic/MainLogic/MainLogic.h"
#include "src/server/lib/CompanyServer/MainServerLogic/DataBaseConnector/DataBaseConnector.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

namespace TestingDataBaseConnectorGmock {

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

    TEST(DataBaseConnector, userIsRegistered) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, userIsRegistered).Times(AtLeast(1));
        std::string login("login");
        dataBaseConnector.userIsRegistered(login);
    }

    TEST(DataBaseConnector, userIsAuthorized) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, userIsAuthorized).Times(AtLeast(1));
        std::string login("login");
        dataBaseConnector.userIsAuthorized(login);
    }

    TEST(DataBaseConnector, authorizeUser) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, authorizeUser).Times(AtLeast(1));
        std::string login("login");
        dataBaseConnector.authorizeUser(login);
    }

    TEST(DataBaseConnector, logoutUser) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, logoutUser).Times(AtLeast(1));
        std::string login("login");
        dataBaseConnector.logoutUser(login);
    }

    TEST(DataBaseConnector, addMessage) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, addMessage).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.addMessage(pt);
    }

    TEST(DataBaseConnector, createChat) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, createChat).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.createChat(pt);
    }

    TEST(DataBaseConnector, deleteChat) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, deleteChat).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.deleteChat(pt);
    }

    TEST(DataBaseConnector, createUser) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, createUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.createUser(pt);
    }

    TEST(DataBaseConnector, deleteUser) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, deleteUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.deleteUser(pt);
    }

    TEST(DataBaseConnector, getUserInfo) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getUserInfo).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.getUserInfo(pt);
    }

    TEST(DataBaseConnector, getChatInfo) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getChatInfo).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.getChatInfo(pt);
    }

    TEST(DataBaseConnector, logRequest) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, logRequest).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.logRequest(pt);
    }

    TEST(DataBaseConnector, getMessageAuthorInfo) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getMessageAuthorInfo).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.getMessageAuthorInfo(pt);
    }

    TEST(DataBaseConnector, getUserChatsPreview) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getUserChatsPreview).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.getUserChatsPreview(pt);
    }

    TEST(DataBaseConnector, getChatMessages) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getChatMessages).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        dataBaseConnector.getChatMessages(pt);
    }

    TEST(DataBaseConnector, getUserChats) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getUserChats).Times(AtLeast(1));
        dataBaseConnector.getUserChats(1);
    }

    TEST(DataBaseConnector, getTeamName) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getTeamName).Times(AtLeast(1));
        dataBaseConnector.getTeamName(1);
    }

    TEST(DataBaseConnector, getChatMessagesCount) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getChatMessagesCount).Times(AtLeast(1));
        dataBaseConnector.getChatMessagesCount(1);
    }

    TEST(DataBaseConnector, getChatMembers) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getChatMembers).Times(AtLeast(1));
        dataBaseConnector.getChatMembers(1);
    }

    TEST(DataBaseConnector, getChatLastMessage) {
        MockDataBaseConnector dataBaseConnector;
        EXPECT_CALL(dataBaseConnector, getChatLastMessage).Times(AtLeast(1));
        dataBaseConnector.getChatLastMessage(1);
    }
}

namespace TestingControllerGmock {

    class MockController: public Controller {
    public:
        MOCK_METHOD1(loginUser, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(logoutUser, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(deleteChat, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(createChat, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(deleteUser, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(getUserChatsPreview, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(getChatInfo, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(command, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(registerUser, boost::property_tree::ptree(boost::property_tree::ptree &params));
    };

    TEST(Controller, loginUser) {
        MockController controller;
        EXPECT_CALL(controller, loginUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.loginUser(pt);
    }

    TEST(Controller, logoutUser) {
        MockController controller;
        EXPECT_CALL(controller, logoutUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.logoutUser(pt);
    }

    TEST(Controller, deleteChat) {
        MockController controller;
        EXPECT_CALL(controller, deleteChat).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.deleteChat(pt);
    }

    TEST(Controller, createChat) {
        MockController controller;
        EXPECT_CALL(controller, createChat).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.createChat(pt);
    }

    TEST(Controller, deleteUser) {
        MockController controller;
        EXPECT_CALL(controller, deleteUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.deleteUser(pt);
    }

    TEST(Controller, getUserChatsPreview) {
        MockController controller;
        EXPECT_CALL(controller, getUserChatsPreview).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.getUserChatsPreview(pt);
    }

    TEST(Controller, getChatInfo) {
        MockController controller;
        EXPECT_CALL(controller, getChatInfo).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.getChatInfo(pt);
    }

    TEST(Controller, command) {
        MockController controller;
        EXPECT_CALL(controller, command).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.command(pt);
    }

    TEST(Controller, registerUser) {
        MockController controller;
        EXPECT_CALL(controller, registerUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        controller.registerUser(pt);
    }

}



namespace TestingAuthorizationManagerGmock {

    class MockAuthorizationManager : public AuthorizationManager {
    public:
        MOCK_METHOD1(loginUser, boost::property_tree::ptree(boost::property_tree::ptree & params));
        MOCK_METHOD1(logoutUser, boost::property_tree::ptree(boost::property_tree::ptree & params));
    };


    TEST(AuthorizationManager, loginUser) {
        MockAuthorizationManager manager;
        EXPECT_CALL(manager, loginUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        manager.loginUser(pt);
    }

}


namespace TestingCommandsManagerGmock {

    class MockCommandsManager : public CommandsManager {
    public:
        MOCK_METHOD1(command, boost::property_tree::ptree(boost::property_tree::ptree & params));
    };


    TEST(CommandsManager, command) {
        MockCommandsManager manager;
        EXPECT_CALL(manager, command).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        manager.command(pt);
    }

}

namespace TestingInfoManagerGmock {

    class MockInfoManager : public InfoManager {
    public:
        MOCK_METHOD1(getMessageAuthorInfo, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(getChatInfo, boost::property_tree::ptree(boost::property_tree::ptree &params));
        MOCK_METHOD1(getUserChatsPreview, boost::property_tree::ptree(boost::property_tree::ptree &params));
    };


    TEST(InfoManager, getMessageAuthorInfo) {
        MockInfoManager manager;
        EXPECT_CALL(manager, getMessageAuthorInfo).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        manager.getMessageAuthorInfo(pt);
    }

    TEST(InfoManager, getChatInfo) {
        MockInfoManager manager;
        EXPECT_CALL(manager, getChatInfo).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        manager.getChatInfo(pt);
    }

    TEST(InfoManager, getUserChatsPreview) {
        MockInfoManager manager;
        EXPECT_CALL(manager, getUserChatsPreview).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        manager.getUserChatsPreview(pt);
    }

}

namespace TestingLogsManagerGmock {

    class MockLogsManager : public LogsManager {
    public:
        MOCK_METHOD1(getServerLogs, boost::property_tree::ptree(boost::property_tree::ptree & params));
    };

    TEST(LogsManager, getServerLogs) {
        MockLogsManager manager;
        EXPECT_CALL(manager, getServerLogs).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        manager.getServerLogs(pt);
    }

}

namespace TestingRegistrationManagerGmock {

    class MockRegistrationManager : public RegistrationManager {
    public:
        MOCK_METHOD1(deleteUser, boost::property_tree::ptree(boost::property_tree::ptree & params));
        MOCK_METHOD1(registerUser, boost::property_tree::ptree(boost::property_tree::ptree & params));
    };

    TEST(RegistrationManager, deleteUser) {
        MockRegistrationManager manager;
        EXPECT_CALL(manager, deleteUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        manager.deleteUser(pt);
    }

    TEST(RegistrationManager, registerUser) {
        MockRegistrationManager manager;
        EXPECT_CALL(manager, registerUser).Times(AtLeast(1));
        boost::property_tree::ptree pt;
        manager.registerUser(pt);
    }
}


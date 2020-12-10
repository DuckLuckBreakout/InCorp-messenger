#include <gmock/gmock.h>

#include <lib/Client/RoleController/RoleController.h>
#include <lib/Client/Client/Client.h>
#include <lib/Client/UserOptions/CompanyOptions.h>
#include <lib/Client/UserOptions/BaseUserOptions.h>
#include <ui/Callbacks/Chat.h>
#include <ui/Callbacks/Login.h>

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

// Test Client
namespace TestingClientGmock {
    class MockClient : public Client {
    public:
        MOCK_METHOD2(startClient, void(const std::string &ip, const std::string &port));
        MOCK_METHOD1(sendMessage, void(const std::string &message));
        MOCK_METHOD1(setMessageHandler, void(const std::function<void(const std::string&)>& handler));
        MOCK_METHOD1(setErrorHandler, void(const std::function<void(int)>& handler));
    };


    TEST(Client, startClient) {
        MockClient client;
        EXPECT_CALL(client, startClient).Times(AtLeast(1));
        client.startClient("127.0.0.1", "5555");
    }
    TEST(Client, sendMessage) {
        MockClient client;
        EXPECT_CALL(client, sendMessage).Times(AtLeast(1));
        client.sendMessage("test");
    }
    TEST(Client, setMessageHandler) {
        MockClient client;
        EXPECT_CALL(client, setMessageHandler).Times(AtLeast(1));
        client.setMessageHandler([](const std::string&) {});
    }
    TEST(Client, setErrorHandler) {
        MockClient client;
        EXPECT_CALL(client, setErrorHandler).Times(AtLeast(1));
        client.setErrorHandler([](int) {});
    }
}


// Test UserOptions
namespace TestingUserOptionsGmock {

    namespace EmployeeOptionsGmock {
        class MockEmployeeOptions : public EmployeeOptions {
        public:
            MOCK_METHOD5(sendMessage, void(const Message& message, int globalId,
                                          const std::shared_ptr<BaseCallback> callback,
                                          std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));

            MOCK_METHOD5(authorization, void(const Authorization& authInfo, int globalId,
                                        const std::shared_ptr<BaseCallback> callback,
                                        std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));

            MOCK_METHOD5(chatUpdate, void(const ChatUpdates& chatUpdates, int globalId,
                                     const std::shared_ptr<BaseCallback> callback,
                                     std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));
        };


        TEST(EmployeeOptions, sendMessage) {
            MockEmployeeOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, sendMessage).Times(AtLeast(1));
            userOptions.sendMessage(Message(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
        TEST(EmployeeOptions, authorization) {
            MockEmployeeOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, authorization).Times(AtLeast(1));
            userOptions.authorization(Authorization(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
        TEST(EmployeeOptions, chatUpdate) {
            MockEmployeeOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, chatUpdate).Times(AtLeast(1));
            userOptions.chatUpdate(ChatUpdates(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
    }

    namespace ManagerOptionsGmock {
        class MockManagerOptions : public ManagerOptions {
        public:
            MOCK_METHOD5(sendMessage, void(const Message& message, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));

            MOCK_METHOD5(authorization, void(const Authorization& authInfo, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));

            MOCK_METHOD5(chatUpdate, void(const ChatUpdates& chatUpdates, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));
        };


        TEST(MockManagerOptions, sendMessage) {
            MockManagerOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, sendMessage).Times(AtLeast(1));
            userOptions.sendMessage(Message(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
        TEST(MockManagerOptions, authorization) {
            MockManagerOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, authorization).Times(AtLeast(1));
            userOptions.authorization(Authorization(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
        TEST(MockManagerOptions, chatUpdate) {
            MockManagerOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, chatUpdate).Times(AtLeast(1));
            userOptions.chatUpdate(ChatUpdates(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
    }



    namespace GuestOptionsGmock {
        class MockGuestOptions : public GuestOptions {
        public:
            MOCK_METHOD5(sendMessage, void(const Message& message, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));

            MOCK_METHOD5(authorization, void(const Authorization& authInfo, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));

            MOCK_METHOD5(chatUpdate, void(const ChatUpdates& chatUpdates, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));
        };


        TEST(MockGuestOptions, sendMessage) {
            MockGuestOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, sendMessage).Times(AtLeast(1));
            userOptions.sendMessage(Message(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
        TEST(MockGuestOptions, authorization) {
            MockGuestOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, authorization).Times(AtLeast(1));
            userOptions.authorization(Authorization(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
        TEST(MockGuestOptions, chatUpdate) {
            MockGuestOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, chatUpdate).Times(AtLeast(1));
            userOptions.chatUpdate(ChatUpdates(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
    }



    namespace CompanyOptionsGmock {
        class MockCompanyOptions : public CompanyOptions {
        public:
            MOCK_METHOD5(sendMessage, void(const Message& message, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));

            MOCK_METHOD5(authorization, void(const Authorization& authInfo, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));

            MOCK_METHOD5(chatUpdate, void(const ChatUpdates& chatUpdates, int globalId,
                    const std::shared_ptr<BaseCallback> callback,
                    std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder));
        };


        TEST(MockCompanyOptions, sendMessage) {
            MockCompanyOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, sendMessage).Times(AtLeast(1));
            userOptions.sendMessage(Message(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
        TEST(MockCompanyOptions, authorization) {
            MockCompanyOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, authorization).Times(AtLeast(1));
            userOptions.authorization(Authorization(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
        TEST(MockCompanyOptions, chatUpdate) {
            MockCompanyOptions userOptions;
            std::shared_ptr<BaseClient> client = std::make_shared<Client>();
            std::shared_ptr<CallbacksHolder> callbackHolder = std::make_shared<CallbacksHolder>();
            EXPECT_CALL(userOptions, chatUpdate).Times(AtLeast(1));
            userOptions.chatUpdate(ChatUpdates(), 1, std::make_shared<BaseCallback>(), client, callbackHolder);
        }
    }
}

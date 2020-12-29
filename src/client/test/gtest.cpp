#include <gtest/gtest.h>

#include <UserOptions/BaseUserOptions.h>
#include <RoleController/RoleController.h>
#include <ChatObjects/UserInfo.h>
#include <ChatObjects/ChatAction.h>
#include <ChatObjects/MessageStatus.h>
#include <Commands/BaseCmd.h>
#include <Commands/CmdCreator/CommandCreator.h>
#include <Commands/AuthorizationCmd.h>
#include <RoleController/RoleController.h>

namespace TestingParser{
    namespace Clear {
        Parser parser;
        TEST(Parser, clearTree) {
            EXPECT_NO_THROW(parser.clear()) << "Can't clear tree";
        }
    }

    namespace getJson {
        Parser parser;
        TEST(Parser, getJsonFromTree) {
            parser.clear();
            parser.addValue("test", "name");
            EXPECT_EQ(parser.getJson(), "{\n    \"name\": \"test\"\n}\n") << "Can't get Json string";
        }
    }

    namespace setJson {
        Parser parser;
        TEST(Parser, setJsonFromTree) {
            parser.clear();
            EXPECT_NO_THROW(parser.setJson("{\n    \"name\": \"test\"\n}\n")) << "Can't set Json string";
        }
    }

    namespace addJsonStr {
        Parser parser;
        TEST(Parser, addJsonStrToTree) {
            parser.clear();
            EXPECT_NO_THROW(parser.addJsonStr("{ \"body\": { \"ip\": \"127.0.0.1\", \"port\": \"5555\" }} ",
                                              "body"));
        }
    }

    namespace addArrayJsonStr {
        Parser parser;
        TEST(Parser, addArrayJsonStr) {
            parser.clear();
            EXPECT_NO_THROW(parser.addJsonStr("{ \"body\": \"[\\\"{}\\\", \\\"{}\\\"]\"} ", "body"));
        }
    }

    namespace getJsonStr {
        Parser parser;
        TEST(Parser, getJsonStr) {
            parser.clear();
            parser.addJsonStr("{ \"body\": { \"ip\": \"127.0.0.1\", \"port\": \"5555\" }} ","body");
            EXPECT_EQ(parser.getJsonStr("body"), "{\n    \"body\": {\n        "
                                                 "\"ip\": \"127.0.0.1\",\n        \"port\": \"5555\"\n    }\n}\n");
        }
    }

    namespace addAndGetValue {
        Parser parser;
        TEST(Parser, addAndGetValue) {
            parser.clear();
            int num = 1;
            float floatNum = 3.2;
            EXPECT_NO_THROW(parser.addValue("test","body"));
            EXPECT_NO_THROW(parser.addValue(num,"num"));
            EXPECT_NO_THROW(parser.addValue(floatNum,"floatNum"));

            EXPECT_EQ(parser.getValue<std::string>("body"), "test");
            EXPECT_EQ(parser.getValue<int>("num"), num);
            EXPECT_EQ(parser.getValue<float>("floatNum"), floatNum);
        }
    }

    namespace addAndGetArray {
        Parser parser;
        TEST(Parser, addAndGetArray) {
            std::vector<int> intArray = {1, 4, 3};
            std::vector<std::string> stringArray = {"test1", "test2"};
            EXPECT_NO_THROW(parser.addArray(intArray, "intArray"));
            EXPECT_NO_THROW(parser.addArray(stringArray, "stringArray"));

            EXPECT_EQ(parser.getArray<int>("intArray"), intArray);
            EXPECT_EQ(parser.getArray<std::string>("stringArray"), stringArray);
        }
    }
}

namespace TestCallbacksHolder {
    namespace addCallback {
        CallbacksHolder callbacksHolder;
        TEST(CallbacksHolder, addNewCallback) {
            BaseCallback callback;
            EXPECT_EQ(callbacksHolder.addCallback(1, std::make_shared<BaseCallback>(callback)), 1);
        }
        TEST(CallbacksHolder, addCallbackWithRequest) {
            BaseCallback callback;
            EXPECT_EQ(callbacksHolder.addCallback(-1, 2, std::make_shared<BaseCallback>(callback)), 2);
        }
    }
    namespace getCallback {
        CallbacksHolder callbacksHolder;
        TEST(CallbacksHolder, commandNotInHolder) {
            EXPECT_THROW(callbacksHolder.getCallback(1, 1), std::runtime_error);
        }
        TEST(CallbacksHolder, commandInHolder) {
            BaseCallback callback;
            EXPECT_EQ(callbacksHolder.addCallback(1, std::make_shared<BaseCallback>(callback)), 1);
            EXPECT_NO_THROW(callbacksHolder.getCallback(1, 1));
        }
    }
}

namespace TestingChatObjects {
    namespace TestChatAction {
        TEST(ChatAction, ChatActionEncode) {
            ChatAction chatAction(1);
            EXPECT_EQ(chatAction.encode(), "{\n    \"chatId\": \"1\"\n}\n");
        }
        TEST(ChatObjects, ChatActionDecode) {
            ChatAction chatAction;
            EXPECT_NO_THROW(chatAction.decode("{\n    \"chatAction\": \"1\"\n}\n"));
            EXPECT_EQ(chatAction.chatAction, 1);
        }
    }

    namespace TestChatItem {
        TEST(ChatItem, ChatItemEncode) {
            ChatItem chatItem(1, "test");
            EXPECT_EQ(chatItem.encode(), "{\n    \"chatId\": \"1\",\n    \"chatName\": \"test\"\n}\n");
        }
        TEST(ChatItem, ChatItemDecode) {
            ChatItem chatItem;
            EXPECT_NO_THROW(chatItem.decode("{\n    \"chatId\": \"1\",\n    \"chatName\": \"test\"\n}\n"));
            EXPECT_EQ(chatItem.chatId, 1);
            EXPECT_EQ(chatItem.chatName, "test");
        }
    }

    namespace TestChatRoom {
        TEST(ChatRoom, ChatRoomEncode) {
            ChatRoom chatRoom(1);
            EXPECT_EQ(chatRoom.encode(), "{\n    \"chatId\": \"1\"\n}\n");
        }
        TEST(ChatRoom, ChatRoomDecode) {
            ChatRoom chatRoom;
            EXPECT_NO_THROW(chatRoom.decode("{\n    \"usersId\": \"[1]\",\n    \"chatName\": \"test\"\n}\n"));
            EXPECT_EQ(chatRoom.chatName, "test");
        }
    }

    namespace TestChatUpdates {
        TEST(ChatUpdates, ChatUpdatesEncode) {
            ChatUpdates chatUpdates(1, 1, 5);
            EXPECT_EQ(chatUpdates.encode(), "{\n    \"chatId\": \"1\",\n    \"lastMessageNum\": \"1\",\n"
                                            "    \"maxNumMessages\": \"5\"\n}\n");
        }
        TEST(ChatUpdates, ChatUpdatesDecode) {
            ChatUpdates chatUpdates;
            EXPECT_THROW(chatUpdates.decode("{\n    \"chatId\": \"1\",\n    \"messages\": \"[]\",\n}\n"),
                                            std::runtime_error);
        }
    }

    namespace TestListChats {
        TEST(ListChats, ListChatsEncode) {
            ListChats listChats;
            EXPECT_EQ(listChats.encode(), "{\n}\n");
        }
        TEST(ListChats, ListChatsDecode) {
            ListChats listChats;
            EXPECT_NO_THROW(listChats.decode("{\n    \"chats\": \"[\\\"{}\\\"]\"\n}\n"));
        }
    }

    namespace TestLog {
        TEST(Log, LogEncode) {
            Log log;
            EXPECT_EQ(log.encode(), "{\n}\n");
        }
        TEST(Log, LogDecode) {
            Log log;
            EXPECT_NO_THROW(log.decode("{\n    \"text\": \"test_text\",\n    "
                                       "\"operation\": \"adding\",\n    "
                                       "\"timeSend\": \"0\",\n    "
                                       "\"number\": \"2\"\n}\n"));
            EXPECT_EQ(log.text, "test_text");
            EXPECT_EQ(log.operation, "adding");
            EXPECT_EQ(log.timeSend, 0);
            EXPECT_EQ(log.number, 2);
        }
    }

    namespace TestLogUpdates {
        TEST(LogUpdates, LogUpdatesEncode) {
            LogUpdates logUpdates(1, 5);
            EXPECT_EQ(logUpdates.encode(), "{\n    \"lastMessageNum\": \"1\",\n"
                                            "    \"maxNumMessages\": \"5\"\n}\n");
        }
        TEST(LogUpdates, LogUpdatesDecode) {
            LogUpdates logUpdates;
            EXPECT_THROW(logUpdates.decode("{\n    \"logs\": \"[]\",\n}\n"),
                         std::runtime_error);
        }
    }

    namespace TestMessage {
        TEST(Message, MessageEncode) {
            Message message(1, "test", 1, 0, 2);
            EXPECT_EQ(message.encode(), "{\n    \"chatId\": \"1\",\n    \"text\": \"test\",\n    "
                                        "\"ownerId\": \"1\",\n    \"timeSend\": \"0\",\n    "
                                        "\"number\": \"2\"\n}\n");
        }
        TEST(Message, MessageDecode) {
            Message message;
            EXPECT_NO_THROW(message.decode("{\n    \"isChecked\": \"true\",\n    "
                                           "\"chatId\": \"1\",\n    \"text\": \"test\",\n    "
                                       "\"ownerId\": \"1\",\n    \"timeSend\": \"0\",\n    "
                                       "\"number\": \"1\"\n}\n"));
            EXPECT_EQ(message.chatId, 1);
            EXPECT_EQ(message.text, "test");
            EXPECT_EQ(message.ownerId, 1);
            EXPECT_EQ(message.timeSend, 0);
            EXPECT_EQ(message.number, 1);
        }
    }

    namespace TestMessageStatus {
        TEST(MessageStatus, MessageStatusEncode) {
            MessageStatus messageStatus(2);
            EXPECT_EQ(messageStatus.encode(), "{\n    \"chatId\": \"2\"\n}\n");
        }
        TEST(MessageStatus, MessageStatusDecode) {
            MessageStatus messageStatus;
            EXPECT_NO_THROW(messageStatus.decode("{\n    \"chatId\": \"2\"\n}\n"));
            EXPECT_EQ(messageStatus.chatId, 2);
        }
    }

    namespace TestRequest {
        TEST(Request, RequestEncode) {
            Request request(1, "{ \"name\" : \"test_name\" }", 1, 1);
            EXPECT_EQ(request.encode(), "{\n    \"command\": \"1\",\n    \"body\": {\n        "
                                        "\"name\": \"test_name\"\n    },\n    \"numRequest\": \"1\",\n    "
                                        "\"globalId\": \"1\"\n}\n");
        }
        TEST(Request, RequestDecode) {
            Request request;
            EXPECT_NO_THROW(request.decode("{\n    \"command\": \"1\",\n    \"body\": {\n        "
                                           "\"name\": \"test_name\"\n    },\n    \"error\": \"test\",\n    "
                                           "\"status\": \"true\",\n    \"numRequest\": \"1\"\n}\n"));
            EXPECT_EQ(request.command, 1);
            EXPECT_EQ(request.status, true);
            EXPECT_EQ(request.numRequest, 1);
        }
    }

    namespace TestUserInfo {
        TEST(UserInfo, UserInfoEncode) {
            Request request(1, "{ \"name\" : \"test_name\" }", 1, 1);
            EXPECT_EQ(request.encode(), "{\n    \"command\": \"1\",\n    \"body\": {\n        "
                                        "\"name\": \"test_name\"\n    },\n    \"numRequest\": \"1\",\n    "
                                        "\"globalId\": \"1\"\n}\n");
        }
        TEST(UserInfo, UserInfoDecode) {
            Request request;
            EXPECT_NO_THROW(request.decode("{\n    \"command\": \"1\",\n    \"body\": {\n        "
                                           "\"name\": \"test_name\"\n    },\n    \"error\": \"test\",\n    "
                                           "\"status\": \"true\",\n    \"numRequest\": \"1\"\n}\n"));
            EXPECT_EQ(request.command, 1);
            EXPECT_EQ(request.status, true);
            EXPECT_EQ(request.numRequest, 1);
        }
    }

    namespace TestUserPreview {
        TEST(UserPreview, UserPreviewEncode) {
            UserPreview userPreview(1, 1);
            EXPECT_EQ(userPreview.encode(), "{\n    \"userId\": \"1\",\n    "
                                        "\"chatId\": \"1\"\n}\n");
        }
        TEST(UserPreview, UserPreviewDecode) {
            UserPreview userPreview;
            EXPECT_NO_THROW(userPreview.decode("{\n    \"userId\": \"1\",\n"
                                               "    \"firstName\": \"test_Name\",\n    "
                                               "\"lastName\": \"test_Surname\",\n    \"role\": \"employee\"\n}\n"));
            EXPECT_EQ(userPreview.userId, 1);
            EXPECT_EQ(userPreview.firstName, "test_Name");
            EXPECT_EQ(userPreview.lastName, "test_Surname");
            EXPECT_EQ(userPreview.role, "employee");
        }
    }
}

namespace TestingCommandCreator {
    TEST(CommandCreator, LogIn) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::LogIn,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, SendMessage) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::SendMessage,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, SystemUpdate) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::SystemUpdate,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, GetListOfChats) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::GetListOfChats,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, GetSelectChatRoom) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::GetSelectChatRoom,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, GetMessagesInChat) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::GetMessagesInChat,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, GetLastMessageInChat) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::GetLastMessageInChat,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, GetUserData) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::GetUserData,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, ChatObserver) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::ChatObserver,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, GetLog) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::GetLog,
                                              std::optional<std::string>(""), "", 1));
    }

    TEST(CommandCreator, RegistrationUser) {
        CommandCreator creator;
        EXPECT_NO_THROW(creator.createCommand(Commands::RegistrationUser,
                                              std::optional<std::string>(""), "", 1));
    }
}

namespace TestingCommands {
    TEST(Commands, AuthorizationCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::LogIn, std::make_shared<BaseCallback>(callback));
        AuthorizationCmd authorizationCmd(1, std::optional<std::string>(""), "");
        EXPECT_NO_THROW(authorizationCmd.execute(std::make_shared<CallbacksHolder>(holder)));
    }

    TEST(Commands, ChatObserverCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::ChatObserver, std::make_shared<BaseCallback>(callback));
        ChatObserverCmd chatObserverCmd(1, std::optional<std::string>(""), "{\n    \"isChecked\": \"true\",\n    "
                                                                           "\"chatId\": \"1\",\n    \"text\": \"test\",\n    "
                                                                           "\"ownerId\": \"1\",\n    \"timeSend\": \"0\",\n    "
                                                                           "\"number\": \"1\", \"chatAction\" : \"1\" \n}\n");
        EXPECT_NO_THROW(chatObserverCmd.execute(std::make_shared<CallbacksHolder>(holder)));
    }

    TEST(Commands, ChatUpdateCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::SystemUpdate, std::make_shared<BaseCallback>(callback));
        ChatUpdateCmd chatUpdateCmd(1, std::optional<std::string>(""), "{\n    \"chatId\": \"1\",\n"
                                                                       "    \"messages\": \"[]\",\n}\n");
        EXPECT_THROW(chatUpdateCmd.execute(std::make_shared<CallbacksHolder>(holder)), std::runtime_error);
    }

    TEST(Commands, GetChatMessagesCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::GetMessagesInChat, std::make_shared<BaseCallback>(callback));
        GetChatMessagesCmd getChatMessagesCmd(1, std::optional<std::string>(""), "{\n    \"chatId\": \"1\",\n"
                                                                                 "    \"messages\": \"[]\",\n}\n");
        EXPECT_THROW(getChatMessagesCmd.execute(std::make_shared<CallbacksHolder>(holder)), std::runtime_error);
    }

    TEST(Commands, GetLastMessageCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::GetLastMessageInChat, std::make_shared<BaseCallback>(callback));
        GetLastMessageCmd getLastMessageCmd(1, std::optional<std::string>(""), "{\n    \"isChecked\": \"true\",\n    "
                                                                               "\"chatId\": \"1\",\n    \"text\": \"test\",\n    "
                                                                               "\"ownerId\": \"1\",\n    \"timeSend\": \"0\",\n    "
                                                                               "\"number\": \"1\"\n}\n");
        EXPECT_NO_THROW(getLastMessageCmd.execute(std::make_shared<CallbacksHolder>(holder)));
    }

    TEST(Commands, GetChatRoomCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::GetSelectChatRoom, std::make_shared<BaseCallback>(callback));
        GetChatRoomCmd getChatRoomCmd(1, std::optional<std::string>(""), "{\n    \"usersId\": \"[1]\",\n    "
                                                                         "\"chatName\": \"test\"\n}\n");
        EXPECT_NO_THROW(getChatRoomCmd.execute(std::make_shared<CallbacksHolder>(holder)));
    }

    TEST(Commands, GetListChatsCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::GetListOfChats, std::make_shared<BaseCallback>(callback));
        GetListChatsCmd getListChatsCmd(1, std::optional<std::string>(""), "{\n    "
                                                                           "\"chats\": \"[\\\"{}\\\"]\"\n}\n");
        EXPECT_NO_THROW(getListChatsCmd.execute(std::make_shared<CallbacksHolder>(holder)));
    }

    TEST(Commands, GetLogCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::GetLog, std::make_shared<BaseCallback>(callback));
        GetLogCmd getLogCmd(1, std::optional<std::string>(""), "{\n    \"logs\": \"[]\",\n}\n");
        EXPECT_THROW(getLogCmd.execute(std::make_shared<CallbacksHolder>(holder)), std::runtime_error);
    }

    TEST(Commands, GetUserCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::GetUserData, std::make_shared<BaseCallback>(callback));
        GetUserCmd getUserCmd(1, std::optional<std::string>(""), "{\n    "
                                                                 "\"chats\": \"[\\\"{}\\\"]\"\n}\n");
        EXPECT_THROW(getUserCmd.execute(std::make_shared<CallbacksHolder>(holder)), std::runtime_error);
    }

    TEST(Commands, RegistrationCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::RegistrationUser, std::make_shared<BaseCallback>(callback));
        RegistrationCmd registrationCmd(1, std::optional<std::string>(""), "{\n    \"command\": \"1\",\n    \"body\": {\n        "
                                                                           "\"name\": \"test_name\"\n    },\n    \"error\": \"test\",\n    "
                                                                           "\"status\": \"true\",\n    \"numRequest\": \"1\"\n}\n");
        EXPECT_NO_THROW(registrationCmd.execute(std::make_shared<CallbacksHolder>(holder)));
    }

    TEST(Commands, SendMessageCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::SendMessage, std::make_shared<BaseCallback>(callback));
        SendMessageCmd registrationCmd(1, std::optional<std::string>(""), "{\n    \"isChecked\": \"true\",\n    "
                                                                          "\"chatId\": \"1\",\n    \"text\": \"test\",\n    "
                                                                          "\"ownerId\": \"1\",\n    \"timeSend\": \"0\",\n    "
                                                                          "\"number\": \"1\"\n}\n");
        EXPECT_NO_THROW(registrationCmd.execute(std::make_shared<CallbacksHolder>(holder)));
    }

    TEST(Commands, SystemUpdateCmd) {
        CallbacksHolder holder;
        BaseCallback callback;
        holder.addCallback(Commands::SystemUpdate, std::make_shared<BaseCallback>(callback));
        SystemUpdateCmd systemUpdateCmd(1, std::optional<std::string>(""), "{\n    \"chatAction\": \"0\"\n}\n");
        EXPECT_NO_THROW(systemUpdateCmd.execute(std::make_shared<CallbacksHolder>(holder)));
    }
}

namespace TestingRoleController {
    namespace TestSetRole {
        TEST(RoleController, setRoleGuest) {
            RoleController roleController;
            std::shared_ptr<BaseUserOptions> userOptions;
            EXPECT_NO_THROW(roleController.setRole(userOptions, "guest"));
        }

        TEST(RoleController, setRoleManager) {
            RoleController roleController;
            std::shared_ptr<BaseUserOptions> userOptions;
            EXPECT_NO_THROW(roleController.setRole(userOptions, "manager"));
        }

        TEST(RoleController, setRoleEmployee) {
            RoleController roleController;
            std::shared_ptr<BaseUserOptions> userOptions;
            EXPECT_NO_THROW(roleController.setRole(userOptions, "employee"));
        }

        TEST(RoleController, setRoleCompany) {
            RoleController roleController;
            std::shared_ptr<BaseUserOptions> userOptions;
            EXPECT_NO_THROW(roleController.setRole(userOptions, "company"));
        }

        TEST(RoleController, setRoleIncorrect) {
            RoleController roleController;
            std::shared_ptr<BaseUserOptions> userOptions;
            EXPECT_THROW(roleController.setRole(userOptions, "test"), std::runtime_error);
        }
    }
}

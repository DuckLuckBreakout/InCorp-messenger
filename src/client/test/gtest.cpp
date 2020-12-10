#include <gtest/gtest.h>

#include <UserOptions/BaseUserOptions.h>
#include <RoleController/RoleController.h>
#include <ChatObjects/Authorization.h>

// Role Controller
namespace TestingRoleController::setRole {
        std::shared_ptr<BaseUserOptions> userOptions = std::make_shared<GuestOptions>();
        RoleController roleController;

        TEST(RoleController, setRoleGuest) {
            EXPECT_NO_THROW(roleController.setRole(userOptions, "guest")) << "Can't "
                                                                             "set role = guest";
        }
        TEST(RoleController, setRoleEmployee) {
            EXPECT_NO_THROW(roleController.setRole(userOptions, "employee")) << "Can't "
                                                                                "set role = employee";
        }
        TEST(RoleController, setRoleManager) {
            EXPECT_NO_THROW(roleController.setRole(userOptions, "manager")) << "Can't "
                                                                               "set role = manager";
        }
        TEST(RoleController, setRoleCompany) {
            EXPECT_NO_THROW(roleController.setRole(userOptions, "company")) << "Can't "
                                                                               "set role = company";
        }
        TEST(RoleController, setRoleIncorrectRole) {
            EXPECT_THROW(roleController.setRole(userOptions, ""), std::runtime_error);
        }
}


// JSON Parser
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
            EXPECT_NO_THROW(parser.addJsonStr("{ \"body\": \"[{}, {}]\"} ", "body"));
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


// Chat Objects
namespace TestingChatObjects {
    namespace Authorization {
        TEST(ChatObjects, AuthorizationDecode) {

        }
    }
}

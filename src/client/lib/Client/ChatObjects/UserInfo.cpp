#include "UserInfo.h"

UserInfo::UserInfo()
        : userId(-1) {}

UserInfo::UserInfo(const std::string& login,
                   const std::string& password)
        : login(login), password(password), userId(-1) {}

std::string UserInfo::encode() const {
    parser->clear();

    parser->addValue(login, KeyWords::login);
    parser->addValue(password, KeyWords::password);

    if (firstName != "") {
        parser->addValue(firstName, KeyWords::firstName);
        parser->addValue(lastName, KeyWords::lastName);
        parser->addValue(role, KeyWords::role);
    }
    return parser->getJson();
}

void UserInfo::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    userId = parser->getValue<int>(KeyWords::userId);
    role = parser->getValue<std::string>(KeyWords::role);
    firstName = parser->getValue<std::string>(KeyWords::firstName);
    lastName = parser->getValue<std::string>(KeyWords::lastName);
    ip = parser->getValue<std::string>(KeyWords::ip);
    port = parser->getValue<std::string>(KeyWords::port);
    company = parser->getValue<std::string>(KeyWords::company);
}

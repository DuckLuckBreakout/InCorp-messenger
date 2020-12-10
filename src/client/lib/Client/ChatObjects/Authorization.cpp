#include "Authorization.h"

Authorization::Authorization() {}

Authorization::Authorization(const std::string& login,
                             const std::string& password)
        : login(login), password(password), userId(-1) {}

std::string Authorization::encode() const {
    parser->clear();

    parser->addValue(login, KeyWords::login);
    parser->addValue(password, KeyWords::password);
    return parser->getJson();
}

void Authorization::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    userId = parser->getValue<int>(KeyWords::userId);
    role = parser->getValue<std::string>(KeyWords::role);
    chatsId = parser->getArray<int>(KeyWords::chatsId);
    firstName = parser->getValue<std::string>(KeyWords::firstName);
    lastName = parser->getValue<std::string>(KeyWords::lastName);
    ip = parser->getValue<std::string>(KeyWords::ip);
    port = parser->getValue<std::string>(KeyWords::port);
}

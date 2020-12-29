#include "UserPreview.h"

UserPreview::UserPreview() : userId(-1) {}

UserPreview::UserPreview(int userId, int chatId)
        : userId(userId), chatId(chatId) {}

std::string UserPreview::encode() const {
    parser->clear();

    parser->addValue(userId, KeyWords::userId);
    parser->addValue(chatId, KeyWords::chatId);
    return parser->getJson();
}

void UserPreview::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    userId = parser->getValue<int>(KeyWords::userId);
    firstName = parser->getValue<std::string>(KeyWords::firstName);
    lastName = parser->getValue<std::string>(KeyWords::lastName);
    role = parser->getValue<std::string>(KeyWords::role);
}


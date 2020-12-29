#include "ChatRoom.h"

ChatRoom::ChatRoom() : chatId(-1) {}

ChatRoom::ChatRoom(int chatId) : chatId(chatId) {}

std::string ChatRoom::encode() const {
    parser->clear();

    parser->addValue(chatId, KeyWords::chatId);
    return parser->getJson();
}

void ChatRoom::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    chatName = parser->getValue<std::string>(KeyWords::chatName);
    usersId = parser->getArray<int>(KeyWords::usersId);
}

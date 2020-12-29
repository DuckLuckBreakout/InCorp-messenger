#include "ChatItem.h"

ChatItem::ChatItem() : chatId(-1) {}

ChatItem::ChatItem(int chatId, const std::string &chatName)
    : chatId(chatId), chatName(chatName){}

std::string ChatItem::encode() const {
    parser->clear();

    parser->addValue(chatId, KeyWords::chatId);
    parser->addValue(chatName, KeyWords::chatName);
    return parser->getJson();
}

void ChatItem::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    chatId = parser->getValue<int>(KeyWords::chatId);
    chatName = parser->getValue<std::string>(KeyWords::chatName);
}

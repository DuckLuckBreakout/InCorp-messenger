#include "MessageStatus.h"

MessageStatus::MessageStatus() : chatId(-1) {}

MessageStatus::MessageStatus(int chatId) : chatId(chatId) {}

std::string MessageStatus::encode() const {
    parser->clear();

    parser->addValue(chatId, KeyWords::chatId);
    return parser->getJson();
}

void MessageStatus::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    chatId = parser->getValue<int>(KeyWords::chatId);
}

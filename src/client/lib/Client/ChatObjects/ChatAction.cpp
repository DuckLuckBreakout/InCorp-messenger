#include "ChatAction.h"

ChatAction::ChatAction() : chatId(-1) {}

ChatAction::ChatAction(int chatId) : chatId(chatId){}

std::string ChatAction::encode() const {
    parser->clear();

    parser->addValue(chatId, KeyWords::chatId);
    return parser->getJson();
}

void ChatAction::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    chatAction = parser->getValue<int>(KeyWords::chatAction);
}

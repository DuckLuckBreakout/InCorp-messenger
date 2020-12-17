#include "Checked.h"

Checked::Checked() : chatId(-1) {}

Checked::Checked(int chatId) : chatId(chatId) {}

std::string Checked::encode() const {
    parser->clear();

    parser->addValue(chatId, KeyWords::chatId);
    return parser->getJson();
}

void Checked::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    chatId = parser->getValue<int>(KeyWords::chatId);
}

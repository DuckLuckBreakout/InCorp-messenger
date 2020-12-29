#include "ChatUpdates.h"

ChatUpdates::ChatUpdates()
        : chatId(-1), lastMessageNum(-1), maxNumMessages(-1) {}

ChatUpdates::ChatUpdates(int chatId, int lastMessageNum,
                         int maxNumMessages)
        : chatId(chatId), lastMessageNum(lastMessageNum),
          maxNumMessages(maxNumMessages) {}

std::string ChatUpdates::encode() const {
    parser->clear();

    parser->addValue(chatId, KeyWords::chatId);
    parser->addValue(lastMessageNum, KeyWords::lastMessageNum);
    parser->addValue(maxNumMessages, KeyWords::maxNumMessages);

    return parser->getJson();
}

void ChatUpdates::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    chatId = parser->getValue<int>(KeyWords::chatId);
    Message message;

    for (const auto& item : parser->getArrayJsonStr(KeyWords::messages)) {
        message.decode(item);
        messages.push_back(message);
    }
}

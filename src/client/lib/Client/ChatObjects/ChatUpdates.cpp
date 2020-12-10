#include "ChatUpdates.h"

ChatUpdates::ChatUpdates() {}

ChatUpdates::ChatUpdates(int chatId, int lastMessageId,
                         int maxNumMessages)
        : chatId(chatId), lastMessageId(lastMessageId),
          maxNumMessages(maxNumMessages) {}

std::string ChatUpdates::encode() const {
    parser->clear();

    parser->addValue(chatId, KeyWords::chatId);
    parser->addValue(lastMessageId, KeyWords::lastMessageId);

    return parser->getJson();
}

void ChatUpdates::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    chatId = parser->getValue<int>(KeyWords::chatId);
    Message message;

    messages.push_back(message);
    for (const auto& item : parser->getArray<std::string>(KeyWords::messages)) {
        message.decode(item);
        messages.push_back(message);
    }
}

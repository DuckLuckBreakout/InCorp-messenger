#include "ListChats.h"

ListChats::ListChats() {}

std::string ListChats::encode() const {
    parser->clear();
    
    return parser->getJson();
}

void ListChats::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    ChatItem chatItem;
    for (const auto& item : parser->getArrayJsonStr(KeyWords::chats)) {
        chatItem.decode(item);
        chats.push_back(chatItem);
    }
}

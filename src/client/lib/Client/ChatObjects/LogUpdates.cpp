#include "LogUpdates.h"

LogUpdates::LogUpdates()
        : lastMessageNum(-1), maxNumMessages(-1) {}

LogUpdates::LogUpdates(int lastMessageNum, int maxNumMessages)
        : lastMessageNum(lastMessageNum), maxNumMessages(maxNumMessages) {}

std::string LogUpdates::encode() const {
    parser->clear();

    parser->addValue(lastMessageNum, KeyWords::lastMessageNum);
    parser->addValue(maxNumMessages, KeyWords::maxNumMessages);

    return parser->getJson();
}

void LogUpdates::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    Log log;

    for (const auto& item : parser->getArrayJsonStr(KeyWords::logs)) {
        log.decode(item);
        logs.push_back(log);
    }
}

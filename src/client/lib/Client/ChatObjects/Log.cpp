#include "Log.h"

Log::Log() {}

std::string Log::encode() const {
    parser->clear();

    return parser->getJson();
}

void Log::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    text = parser->getValue<std::string>(KeyWords::text);
    operation = parser->getValue<std::string>(KeyWords::operation);
    timeSend = parser->getValue<int>(KeyWords::timeSend);
    number = parser->getValue<unsigned int>(KeyWords::number);
}

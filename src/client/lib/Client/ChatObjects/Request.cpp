#include "Request.h"
Request::Request() {}

Request::Request(int command, std::string body,
                 int globalId, int numRequest)
        : command(command), body(std::move(body)),
          globalId(globalId), numRequest(numRequest) {}

std::string Request::encode() const {
    parser->clear();

    parser->addValue(command, KeyWords::command);
    parser->addJsonStr(body, KeyWords::body);
    parser->addValue(numRequest, KeyWords::numRequest);
    parser->addValue(globalId, KeyWords::globalId);
    return parser->getJson();
}


void Request::decode(const std::string& jsonStr) {

    parser->setJson(jsonStr);

    command = parser->getValue<int>(KeyWords::command);
    error = parser->getValue<std::string>(KeyWords::error);
    status = parser->getValue<bool>(KeyWords::status);
    body = parser->getJsonStr(KeyWords::body);
    numRequest = parser->getValue<int>(KeyWords::numRequest);
}

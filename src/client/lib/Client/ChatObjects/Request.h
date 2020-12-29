#ifndef APPLICATION_REQUEST_H
#define APPLICATION_REQUEST_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


class Request : public BaseObject {
public:
    Request();
    Request(int command, std::string body,
            int globalId, int numRequest);
    ~Request() override = default;

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int command;
    std::string error;
    bool status;
    std::string body;
    int globalId;
    int numRequest;
};


#endif //APPLICATION_REQUEST_H

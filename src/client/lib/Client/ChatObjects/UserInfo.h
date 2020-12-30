#ifndef APPLICATION_USERINFO_H
#define APPLICATION_USERINFO_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


// Info about user
class UserInfo : public BaseObject {
public:
    UserInfo();
    UserInfo(const std::string& login, const std::string& password);
    ~UserInfo() override = default;

    // Get encode string
    std::string encode() const override;

    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    int userId;
    std::string role;
    std::string firstName;
    std::string lastName;
    std::string login;
    std::string password;
    std::string ip;
    std::string port;
    std::string company;
};


#endif //APPLICATION_USERINFO_H

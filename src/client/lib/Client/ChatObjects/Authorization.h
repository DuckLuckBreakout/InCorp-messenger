#ifndef APPLICATION_AUTHORIZATION_H
#define APPLICATION_AUTHORIZATION_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


class Authorization : public BaseObject {
public:
    Authorization();
    Authorization(const std::string& login, const std::string& password);

    std::string encode() const override;
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


#endif //APPLICATION_AUTHORIZATION_H

#ifndef APPLICATION_USER_H
#define APPLICATION_USER_H

#include "BaseObject.h"
#include "KeyWords.h"


class User : public BaseObject {
public:
    User();
    User(int userId, int chatId);

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int userId;
    std::string firstName;
    std::string lastName;
    std::string role;
    int chatId;
};

#endif //APPLICATION_USER_H

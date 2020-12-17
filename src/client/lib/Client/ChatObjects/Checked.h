#ifndef APPLICATION_CHECKED_H
#define APPLICATION_CHECKED_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


class Checked : public BaseObject {
public:
    Checked();
    Checked(int chatId);

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
};



#endif //APPLICATION_CHECKED_H

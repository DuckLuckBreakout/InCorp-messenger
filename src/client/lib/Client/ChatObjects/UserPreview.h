#ifndef APPLICATION_USERPREVIEW_H
#define APPLICATION_USERPREVIEW_H

#include "BaseObject.h"
#include "KeyWords.h"


class UserPreview : public BaseObject {
public:
    UserPreview();
    UserPreview(int userId, int chatId);
    ~UserPreview() override = default;

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int userId;
    std::string firstName;
    std::string lastName;
    std::string role;
    int chatId;
};

#endif //APPLICATION_USERPREVIEW_H

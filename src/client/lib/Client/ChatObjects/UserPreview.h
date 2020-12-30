#ifndef APPLICATION_USERPREVIEW_H
#define APPLICATION_USERPREVIEW_H

#include "BaseObject.h"
#include "KeyWords.h"


// User preview in select chat
class UserPreview : public BaseObject {
public:
    UserPreview();
    UserPreview(int userId, int chatId);
    ~UserPreview() override = default;

    // Get encode string
    std::string encode() const override;

    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    int userId;
    std::string firstName;
    std::string lastName;
    std::string role;
    int chatId;
};

#endif //APPLICATION_USERPREVIEW_H

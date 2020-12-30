#ifndef APPLICATION_MESSAGESTATUS_H
#define APPLICATION_MESSAGESTATUS_H

#include <string>

#include "BaseObject.h"
#include "KeyWords.h"


// Message status of reading 
class MessageStatus : public BaseObject {
public:
    MessageStatus();
    MessageStatus(int chatId);
    ~MessageStatus() override = default;

	// Get encode string
    std::string encode() const override;

    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
};



#endif //APPLICATION_MESSAGESTATUS_H

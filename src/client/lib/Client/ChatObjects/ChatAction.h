#ifndef APPLICATION_CHATACTION_H
#define APPLICATION_CHATACTION_H

#include "BaseObject.h"
#include "Message.h"


// Chat action for system callback
class ChatAction : public BaseObject {
public:
    ChatAction();
    ChatAction(int chatId);
    ~ChatAction() override = default;

	// Get encode string
    std::string encode() const override;
    
    // Set string for decoding
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
    int chatAction;
    std::shared_ptr<BaseObject> data;
};


#endif //APPLICATION_CHATACTION_H

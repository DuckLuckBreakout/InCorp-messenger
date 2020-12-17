#ifndef APPLICATION_CHATACTION_H
#define APPLICATION_CHATACTION_H

#include "BaseObject.h"
#include "Message.h"

class ChatAction : public BaseObject {
public:
    ChatAction();
    ChatAction(int chatId);

    std::string encode() const override;
    void decode(const std::string& jsonStr) override;

public:
    int chatId;
    int chatAction;
    std::shared_ptr<BaseObject> data;
};


#endif //APPLICATION_CHATACTION_H

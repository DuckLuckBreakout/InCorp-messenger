#ifndef APPLICATION_BASECALLBACK_H
#define APPLICATION_BASECALLBACK_H

#include <iostream>

#include "ChatObjects/Authorization.h"
#include "ChatObjects/BaseObject.h"


class BaseCallback {
public:
    BaseCallback() {};
    virtual void operator()(std::shared_ptr<BaseObject> callback,
                            const std::optional<std::string>& error) {};
};


#endif //APPLICATION_BASECALLBACK_H

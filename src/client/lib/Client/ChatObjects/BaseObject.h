#ifndef APPLICATION_BASEOBJECT_H
#define APPLICATION_BASEOBJECT_H

#include <string>
#include <memory>

#include "Parser/Parser.h"


// Abstract chat object
class BaseObject {
public:
    BaseObject() : parser(std::make_shared<Parser>()) {};
    virtual ~BaseObject() = default;

    // Get encode string
    virtual std::string encode() const = 0;
    
    // Set string for decoding
    virtual void decode(const std::string& jsonStr) = 0;

protected:
    std::shared_ptr<Parser> parser;
};


#endif //APPLICATION_BASEOBJECT_H

#ifndef APPLICATION_BASECMD_H
#define APPLICATION_BASECMD_H

#include <utility>

#include "CallbacksHolder/CallbacksHolder.h"


// Abstract command
class BaseCmd {
public:
    virtual ~BaseCmd() = default;

    BaseCmd(int numRequest, const std::optional<std::string>& error,
            const std::string& body);

    // Execute command
    virtual void execute(std::shared_ptr<CallbacksHolder> holder) = 0;

protected:
    int numRequest;
    std::optional<std::string> error;
    const std::string body;
};


#endif //APPLICATION_BASECMD_H

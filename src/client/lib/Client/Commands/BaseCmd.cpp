#include "BaseCmd.h"

BaseCmd::BaseCmd(int numRequest, const std::optional<std::string>& error,
                 const std::string& body)
        : numRequest(numRequest), error(std::move(error)), body(body) {}

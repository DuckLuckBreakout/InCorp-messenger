#include "BaseCmd.h"

BaseCmd::BaseCmd(int numRequest, std::optional<std::string> error,
                 std::string body)
        : numRequest(numRequest), error(std::move(error)), body(std::move(body)) {}

#ifndef TP_PPROJECT_BASEROLECONTROLLER_H
#define TP_PPROJECT_BASEROLECONTROLLER_H

#include <memory>

#include "Client/UserOptions/BaseUserOptions.h"
#include "Client/UserOptions/EmployeeOptions.h"
#include "Client/UserOptions/ManagerOptions.h"
#include "Client/UserOptions/GuestOptions.h"

class BaseRoleController {
public:
    virtual ~BaseRoleController() = default;

    virtual void setRole(std::shared_ptr<BaseUserOptions>& userOptions,
                         const std::string& role) = 0;

};


#endif

#ifndef TP_PPROJECT_ROLECONTROLLER_H
#define TP_PPROJECT_ROLECONTROLLER_H

#include <memory>

#include "UserOptions/BaseUserOptions.h"
#include "UserOptions/GuestOptions.h"
#include "UserOptions/EmployeeOptions.h"
#include "UserOptions/ManagerOptions.h"
#include "UserOptions/CompanyOptions.h"


// Role controller for swap user options
class RoleController {
public:
	// Set new user role
    static void setRole(std::shared_ptr<BaseUserOptions>& userOptions,
                        const std::string& role);
};


#endif

#include "RoleController.h"

void RoleController::setRole(std::shared_ptr<BaseUserOptions>& userOptions,
                             const std::string& role) {
    if (role == "guest") {
        userOptions = std::make_shared<GuestOptions>();
    }
    else if (role == "manager") {
        userOptions = std::make_shared<ManagerOptions>();
    }
    else if (role == "employee") {
        userOptions = std::make_shared<EmployeeOptions>();
    }
    else if (role == "company") {
        userOptions = std::make_shared<CompanyOptions>();
    }
    else {
        throw std::runtime_error("Incorrect user role!");
    }
}

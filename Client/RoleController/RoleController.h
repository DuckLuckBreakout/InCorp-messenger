#ifndef TP_PPROJECT_ROLECONTROLLER_H
#define TP_PPROJECT_ROLECONTROLLER_H

#include "BaseRoleController.h"

class RoleController : public BaseRoleController {
public:
    ~RoleController() override;

    void setRole(std::shared_ptr<BaseUserOptions>& userOptions,
                 const std::string& role) override;
};


#endif

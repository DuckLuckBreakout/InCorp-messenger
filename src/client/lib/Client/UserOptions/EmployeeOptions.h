#ifndef TP_PPROJECT_EMPLOYEEOPTIONS_H
#define TP_PPROJECT_EMPLOYEEOPTIONS_H

#include <iostream>

#include "BaseUserOptions.h"

class EmployeeOptions : public BaseUserOptions {
public:
    ~EmployeeOptions() override = default;

    void getLog(const LogUpdates& logUpdates, int globalId,
                const std::shared_ptr<BaseCallback> callback,
                std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

    void registration(const UserInfo& authInfo, int globalId,
                      const std::shared_ptr<BaseCallback> callback,
                      std::shared_ptr<BaseClient> client, std::shared_ptr<CallbacksHolder> callbackHolder) override;

};


#endif

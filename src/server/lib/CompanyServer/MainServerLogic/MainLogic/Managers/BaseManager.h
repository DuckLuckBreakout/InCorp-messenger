#ifndef TP_PPROJECT_BASEMANAGER_H
#define TP_PPROJECT_BASEMANAGER_H

#include "src/server/lib/CompanyServer/MainServerLogic/DataBaseConnector/DataBaseConnector.h"

class BaseManager {
public:
    explicit BaseManager(std::string companyName="tp") : dbConnector(companyName) {};
    virtual ~BaseManager() = default;

protected:
    DataBaseConnector dbConnector;
};


#endif //TP_PPROJECT_BASEMANAGER_H

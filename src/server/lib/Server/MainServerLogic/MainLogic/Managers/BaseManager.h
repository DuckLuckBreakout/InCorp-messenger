#ifndef TP_PPROJECT_BASEMANAGER_H
#define TP_PPROJECT_BASEMANAGER_H

#include "src/server/lib/Server/MainServerLogic/DataBaseConnector/DataBaseConnector.h"

class BaseManager {
public:
    explicit BaseManager(std::string companyName="test_company") : dbConnector(companyName) {};
    virtual ~BaseManager() = default;

public:
    DataBaseConnector dbConnector;
};


#endif //TP_PPROJECT_BASEMANAGER_H

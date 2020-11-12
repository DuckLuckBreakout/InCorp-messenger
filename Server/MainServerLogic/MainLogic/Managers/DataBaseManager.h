#ifndef TP_PPROJECT_DATABASEMANAGER_H
#define TP_PPROJECT_DATABASEMANAGER_H

#include "BaseManager.h"

class DataBaseManager: public BaseManager {
public:
    ~DataBaseManager() override = default;

    void connectDB();
    void disconnectDB();
    void readFromDB();
    void writeIntoDB();
};


#endif //TP_PPROJECT_DATABASEMANAGER_H

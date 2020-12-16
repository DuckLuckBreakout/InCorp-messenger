#ifndef TP_PPROJECT_BASECONNECTIONCREATOR_H
#define TP_PPROJECT_BASECONNECTIONCREATOR_H

#include "src/libs/Connection/BaseConnection.h"

class BaseConnectionCreator {
public:
    virtual ~BaseConnectionCreator() = default;

    virtual BaseConnection* createConnection() = 0;
};


#endif

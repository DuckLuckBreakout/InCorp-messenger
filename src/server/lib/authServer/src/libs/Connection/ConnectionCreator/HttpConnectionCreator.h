#ifndef TP_PPROJECT_HTTPCONNECTIONCREATOR_H
#define TP_PPROJECT_HTTPCONNECTIONCREATOR_H

#include "BaseConnectionCreator.h"

class HttpConnectionCreator : public BaseConnectionCreator {
public:
    ~HttpConnectionCreator() override;

    BaseConnection* createConnection() override;
};


#endif

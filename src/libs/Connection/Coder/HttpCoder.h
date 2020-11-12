#ifndef TP_PPROJECT_HTTPCODER_H
#define TP_PPROJECT_HTTPCODER_H

#include "BaseCoder.h"

class HttpCoder : public BaseCoder {
public:
    ~HttpCoder() override;

    std::string encode(std::string message) override;
    std::string decode(std::string message) override;
};


#endif

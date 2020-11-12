#ifndef TP_PPROJECT_BASECODER_H
#define TP_PPROJECT_BASECODER_H

#include <iostream>

class BaseCoder {
public:
    virtual ~BaseCoder() = default;

    virtual std::string encode(std::string message) = 0;
    virtual std::string decode(std::string message) = 0;
};


#endif

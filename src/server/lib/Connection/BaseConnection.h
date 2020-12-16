#ifndef TP_PPROJECT_BASECONNECTION_H
#define TP_PPROJECT_BASECONNECTION_H

#include <iostream>
#include <deque>
#include <boost/asio/detail/array.hpp>
class BaseConnection {
public:
    virtual ~BaseConnection() {}
    virtual void on_message(std::string &msg) = 0;
};

#endif

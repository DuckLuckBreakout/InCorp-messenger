#ifndef TP_PPROJECT_BASECONNECTION_H
#define TP_PPROJECT_BASECONNECTION_H

#include <iostream>
#include <deque>
#include <boost/asio/detail/array.hpp>

/*
 * Base class of connection
 */
class BaseConnection {
public:
    virtual ~BaseConnection() {}

    /*
     * Sending a response to the client
     */
    virtual void onMessage(std::string &msg) = 0;
};
#endif

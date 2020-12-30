#include <thread>
#include <boost/asio.hpp>
#include <iostream>
#include "WorkerThread.h"


std::mutex WorkerThread::m;

void WorkerThread::run(std::shared_ptr<boost::asio::io_service> io_service) {

    {
        std::lock_guard < std::mutex > lock(m);
    }

    io_service->run();

    {
        std::lock_guard < std::mutex > unlock(m);
    }
}

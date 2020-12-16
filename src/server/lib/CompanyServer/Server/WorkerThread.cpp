#include <thread>
#include <boost/asio.hpp>
#include <mutex>
#include <iostream>
#include "WorkerThread.h"

using boost::asio::ip::tcp;

std::mutex worker_thread::m;

void worker_thread::run(std::shared_ptr<boost::asio::io_service> io_service) {

    {
        std::lock_guard < std::mutex > lock(m);
        std::cout << "[" << std::this_thread::get_id() << "] Thread starts" << std::endl;
    }

    io_service->run();

    {
        std::lock_guard < std::mutex > unlock(m);
        std::cout << "[" << std::this_thread::get_id() << "] Thread ends" << std::endl;
    }
}

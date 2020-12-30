#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

using boost::asio::ip::tcp;

/*
 * Worker thread class
 */
class WorkerThread {
public:

    /*
     * Worker run method
     */
    static void run(std::shared_ptr<boost::asio::io_service> io_service);
private:
    static std::mutex m;
};


#endif

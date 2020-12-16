#ifndef TCP_WORKERTHREAD_H
#define TCP_WORKERTHREAD_H

using boost::asio::ip::tcp;


class worker_thread {
public:
    static void run(std::shared_ptr<boost::asio::io_service> io_service);
private:
    static std::mutex m;
};


#endif //TCP_WORKERTHREAD_H

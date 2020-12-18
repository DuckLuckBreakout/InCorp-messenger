#include "src/server/lib/CompanyServer/Server/Server.h"
#include <boost/asio.hpp>
#include "src/server/lib/Connection/Connection.h"
#include <boost/thread/thread.hpp>
#include <thread>
#include <mutex>
#include "src/server/lib/CompanyServer/Server/WorkerThread.h"
#include <mongocxx/instance.hpp>


using boost::asio::ip::tcp;


int main() {
    try
    {
        mongocxx::instance instance{};

        std::shared_ptr<boost::asio::io_service> io_service(new boost::asio::io_service);
        boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(*io_service));
        boost::shared_ptr<boost::asio::io_service::strand> strand(new boost::asio::io_service::strand(*io_service));

        std::cout << "[" << std::this_thread::get_id() << "]" << "Server starts" << std::endl;


        tcp::endpoint endpoint(tcp::v4(), 5556);
        Server server = Server(*io_service, *strand, endpoint);

        boost::thread_group workers;
        for (int i = 0; i < 1; ++i) {
            boost::thread * t = new boost::thread{ [io_service] { return worker_thread::run(io_service); } };
            workers.add_thread(t);
        }
        workers.join_all();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

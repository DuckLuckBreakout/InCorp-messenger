#include "src/server/lib/CompanyServer/Server/HttpServer.h"
#include <boost/asio.hpp>
#include "src/server/lib/Connection/HttpConnection.h"
#include <boost/thread/thread.hpp>
#include <thread>
#include <mutex>
#include "src/server/lib/CompanyServer/Server/WorkerThread.h"
#include <mongocxx/instance.hpp>


using boost::asio::ip::tcp;

//----------------------------------------------------------------------

int main(int argc, char* argv[]) {
    try
    {
        mongocxx::instance instance{};
//
        std::shared_ptr<boost::asio::io_service> io_service(new boost::asio::io_service);
        boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(*io_service));
        boost::shared_ptr<boost::asio::io_service::strand> strand(new boost::asio::io_service::strand(*io_service));

        std::cout << "[" << std::this_thread::get_id() << "]" << "Server starts" << std::endl;

        std::list <std::shared_ptr<HttpServer>> Servers;

        tcp::endpoint endpoint(tcp::v4(), 5555);
        std::shared_ptr<HttpServer> a_Server(new HttpServer(*io_service, *strand, endpoint));
        Servers.push_back(a_Server);

        boost::thread_group workers;
        for (int i = 0; i < 1; ++i)
        {
            boost::thread * t = new boost::thread{ boost::bind(&worker_thread::run, io_service) };
            workers.add_thread(t);
        }

        workers.join_all();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

#include "src/server/lib/CompanyServer/Server/Server.h"
#include <boost/asio.hpp>
#include "src/server/lib/Connection/Connection.h"
#include <boost/thread/thread.hpp>
#include <thread>
#include <mutex>
#include "src/server/lib/CompanyServer/Server/WorkerThread.h"
#include <mongocxx/instance.hpp>


using boost::asio::ip::tcp;


int main(int argc, char *argv[]) {
//    std::stringstream convert(argv[1]);
//    std::string message;
//    getline(convert, message, '\a');
//
//    std::cout << message;
//
//
//    boost::asio::io_service service;
//
//    using namespace boost::asio::ip;
//    tcp::endpoint endpoint(address::from_string("192.168.0.70"), 5556);
//    tcp::socket socket(service);
//    std::cout << "[Client] Connecting to server..." << std::endl;
//    socket.connect(endpoint);
//    std::cout << "[Client] Connection successful" << std::endl;
//    service.run();
//
//
//    boost::property_tree::ptree params;
//    std::istringstream is(message);
//    boost::property_tree::read_json(is, params);
//
//    std::string noticeTitle = params.get<std::string>("body.text");
//    noticeTitle = noticeTitle.substr(noticeTitle.find("title: ") + 7, noticeTitle.find("\ntext: ") - (noticeTitle.find("title: ") + 7));
//    std::cout << "NoticeTitle " << noticeTitle << std::endl;
//
//    std::string noticeText = params.get<std::string>("body.text");
//    noticeText = noticeText.substr(noticeText.find("\ntext: ") + 7, noticeText.find("\ntime") - (noticeText.find("\ntext: ") + 7));;
//    std::cout << "noticeText " << noticeText << std::endl;
//
//
//    std::string timeForNotice = params.get<std::string>("body.text");
//    timeForNotice = timeForNotice.substr(timeForNotice.length() - 5, timeForNotice.length());
//    std::cout << "timeForNotice " << timeForNotice << std::endl;
//
//
//    sleep(10);
//    params.put("command", "1");
//    params.put("numRequest", "1");
//    params.put("globalId", "0");
//    params.put("body.text", std::string("NOTICE:\n") + noticeTitle + "\n" + noticeText + "\n");
//    params.put("body.ownerId", "0");
//    params.put("body.timeSend", std::time(nullptr));
//    std::stringstream request;
//    boost::property_tree::json_parser::write_json(request, params);
//
//    socket.write_some(boost::asio::buffer(request.str() + "\r\n"));
//
//    exit(0);

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
//
//#include <cstdint>
//#include <iostream>
//#include <vector>
//#include <bsoncxx/json.hpp>
//#include <mongocxx/client.hpp>
//#include <mongocxx/stdx.hpp>
//#include <mongocxx/uri.hpp>
//#include <mongocxx/instance.hpp>
//#include <bsoncxx/builder/stream/helpers.hpp>
//#include <bsoncxx/builder/stream/document.hpp>
//#include <bsoncxx/builder/stream/array.hpp>
//
//
//using bsoncxx::builder::stream::close_array;
//using bsoncxx::builder::stream::close_document;
//using bsoncxx::builder::stream::document;
//using bsoncxx::builder::stream::finalize;
//using bsoncxx::builder::stream::open_array;
//using bsoncxx::builder::stream::open_document;
//
//int main() {
//    mongocxx::instance instance{}; // This should be done only once.
//    mongocxx::uri uri("mongodb://test_mongo:27017");
//    mongocxx::client client(uri);
//}
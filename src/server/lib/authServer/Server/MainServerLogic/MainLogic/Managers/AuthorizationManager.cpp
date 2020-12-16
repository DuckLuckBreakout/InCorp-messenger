#include "AuthorizationManager.h"
#include <stdlib.h>
#include <boost/property_tree/json_parser.hpp>
#include "src/libs/Connection/HttpConnection.h"
#include <boost/asio.hpp>

boost::property_tree::ptree AuthorizationManager::loginUser(boost::property_tree::ptree &params) {
    std::string login = params.get<std::string>("body.login");
    std::cout << login << std::endl;


    boost::asio::io_service service;

    using namespace boost::asio::ip;
    tcp::endpoint endpoint(address::from_string("192.168.1.115"), 5556);
    tcp::socket socket(service);
    std::cout << "[Client] Connecting to server..." << std::endl;
    socket.connect(endpoint);
    std::cout << "[Client] Connection successful" << std::endl;
    service.run();
    std::cerr << "thread is " << pthread_self() << std::endl;


    std::stringstream request;
    boost::property_tree::json_parser::write_json(request, params);

    int n = socket.write_some(boost::asio::buffer(request.str()));
    std::cerr << "was send message to main server: [ " << n << " ] ";
    std::cerr << "simple: " << (request.str() + "\r\n") << "\n";

    std::string readBuff;
    boost::asio::streambuf response;
    char tmp[1024];
    sleep(5);
//    boost::asio::read_until(socket, response, "\r\n"); // Читаем запрос
    n = socket.read_some(boost::asio::buffer(tmp));
//    std::istream(&response) >> readBuff;

    std::cerr << "was read from main server message: [ " << n << " ] ";
    for (int i = 0; i < n; i++)
        readBuff += tmp[i];
    std::cerr << readBuff << std::endl;

    socket.close();
//    if (dbConnector.userIsRegistered(login)) {
//        dbConnector.authorizeUser(login);
//        params.add("status", "true");
//        params.add("body.userId", 1234);
//        params.add("body.chatsId", "[1, 2, 3]");
//        params.add("body.firstName", "Ivan");
//        params.add("body.lastName", "Kovalenko");
//        params.add("error", "");
//        params.add("body.ip", "192.168.1.115");
//        params.add("body.port", "5556");
//        params.put("body.role", "employee");
//
//    }
//    else
//        params.add("status", "false");

    boost::property_tree::ptree pt;
    std::istringstream is(readBuff);
    boost::property_tree::read_json(is, pt);
    pt.add("body.ip", "192.168.1.115");
    pt.add("body.port", "5556");
    params = pt;
    return params;
}


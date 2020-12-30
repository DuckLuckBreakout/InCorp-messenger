#include "AuthorizationManager.h"


boost::property_tree::ptree AuthorizationManager::loginUser(boost::property_tree::ptree &params) {

    std::string login = params.get<std::string>("body.login");
    std::cout << login << std::endl;


    boost::asio::io_service service;

    using namespace boost::asio::ip;
    std::string company = login.substr(login.find("@") + 1, login.length());
    int port;
    if (company == "tp")
        port = 5556;
    else if (company == "bmstu")
        port = 5557;
    else if (company == "NotDuckLuck")
        port = 5558;
    tcp::endpoint endpoint(address::from_string("192.168.0.70"), port);
    tcp::socket socket(service);
    std::cout << "[Client] Connecting to server..." << std::endl;
    socket.connect(endpoint);
    std::cout << "[Client] Connection successful" << std::endl;
    service.run();
    std::cerr << "thread is " << pthread_self() << std::endl;

    params.put("body.login", login.substr(0, login.find("@")));
    std::stringstream request;
    boost::property_tree::json_parser::write_json(request, params);

    int n = socket.write_some(boost::asio::buffer(request.str() + "\r\n"));
    std::string readBuff;
    boost::asio::streambuf response;
    char tmp[1024];
    n = socket.read_some(boost::asio::buffer(tmp));
    for (int i = 0; i < n; i++)
        readBuff += tmp[i];

    socket.close();

    boost::property_tree::ptree pt;
    std::istringstream is(readBuff);
    boost::property_tree::read_json(is, pt);
    params = pt;

    return params;
}

#ifndef APPLICATION_DATABASECONNECTOR_H
#define APPLICATION_DATABASECONNECTOR_H

#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <boost/property_tree/ptree.hpp>


using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::kvp;


class DataBaseConnector {
public:
    explicit DataBaseConnector(std::string companyName);
    bool userIsRegistered(std::string token);
    bool userIsAuthorized(std::string token);
    void authorizeUser(std::string token);
    void logoutUser(std::string token);
    void addMessage(boost::property_tree::ptree &params);
    void createChat(boost::property_tree::ptree &params);
    void deleteChat(boost::property_tree::ptree &params);
    void deleteUser(boost::property_tree::ptree &params);

private:
    mongocxx::uri uri;
    mongocxx::client client;
    mongocxx::database db;
};
#endif //APPLICATION_DATABASECONNECTOR_H

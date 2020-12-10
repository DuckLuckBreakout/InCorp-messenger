#include "DataBaseConnector.h"

#include <utility>
#include <boost/property_tree/json_parser.hpp>

DataBaseConnector::DataBaseConnector(std::string companyName) :
        uri("mongodb://localhost:27017"),
        client(uri) {
    db = client[companyName];
}

bool DataBaseConnector::userIsRegistered(std::string login) {
    mongocxx::collection coll = db["users"];
    if (coll.find_one(document{} << "login" << login << finalize))
        return true;
    else
        return false;
}

void DataBaseConnector::authorizeUser(std::string login) {
    mongocxx::collection coll = db["authorized_users"];
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(document{} << "login" << login << finalize);
}

bool DataBaseConnector::userIsAuthorized(std::string login) {
    mongocxx::collection coll = db["authorized_users"];
    if (coll.find_one(document{} << "login" << login << finalize))
        return true;
    else
        return false;
}

void DataBaseConnector::logoutUser(std::string login) {
    mongocxx::collection coll = db["authorized_users"];
    coll.delete_one(document{} << "login" << login << finalize);
}

void DataBaseConnector::addMessage(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db[params.get<std::string>("body.chatId")];
    boost::property_tree::ptree body = params.get_child("body");
    std::stringstream messageStream;
    boost::property_tree::json_parser::write_json(messageStream, body);
    bsoncxx::document::value messageDoc = bsoncxx::from_json(messageStream.str());
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(messageDoc.view());
}

void DataBaseConnector::createChat(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db[params.get<std::string>("body.chatId")];
    boost::property_tree::ptree body = params.get_child("body");
    std::stringstream chatInfoStream;
    boost::property_tree::json_parser::write_json(chatInfoStream, body);
    bsoncxx::document::value chatInfoDoc = bsoncxx::from_json(chatInfoStream.str());
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(chatInfoDoc.view());

}

void DataBaseConnector::deleteChat(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db[params.get<std::string>("body.chatId")];
    coll.drop();
}

void DataBaseConnector::deleteUser(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db["users"];
    coll.delete_one(document{} << "login" << params.get<std::string>("body.login") << finalize);
}

void DataBaseConnector::createUser(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db["users"];
    boost::property_tree::ptree body = params.get_child("body");
    std::stringstream userInfoStream;
    boost::property_tree::json_parser::write_json(userInfoStream, body);
    bsoncxx::document::value userInfoDoc = bsoncxx::from_json(userInfoStream.str());
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(userInfoDoc.view());
    //coll.insert_one(document{} << "token" << params.get<std::string>("body.login") << finalize);
}

void DataBaseConnector::getUserInfo(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db["users"];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "login" << params.get<std::string>("body.login") << finalize);
    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);
    params.add("body.userId", pt.get<int>("userId"));
    params.add("body.chatsId", pt.get<std::string>("chatsId"));
    params.add("body.firstName", pt.get<std::string>("firstName"));
    params.add("body.lastName", pt.get<std::string>("lastName"));
    params.add("body.role", pt.get<std::string>("role"));
}
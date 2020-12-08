#include "DataBaseConnector.h"

#include <utility>
#include <boost/property_tree/json_parser.hpp>

DataBaseConnector::DataBaseConnector(std::string companyName) :
        uri("mongodb://localhost:27017"),
        client(uri) {
    db = client[companyName];
}

bool DataBaseConnector::userIsRegistered(std::string token) {
    mongocxx::collection coll = db["users"];
    if (coll.find_one(document{} << "token" << token << finalize))
        return true;
    else
        return false;
}

void DataBaseConnector::authorizeUser(std::string token) {
    mongocxx::collection coll = db["authorized_users"];
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(document{} << "token" << token << finalize);


}

bool DataBaseConnector::userIsAuthorized(std::string token) {
    mongocxx::collection coll = db["authorized_users"];
    if (coll.find_one(document{} << "token" << token << finalize))
        return true;
    else
        return false;
}

void DataBaseConnector::logoutUser(std::string token) {
    mongocxx::collection coll = db["authorized_users"];
    coll.delete_one(document{} << "token" << token << finalize);
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
    mongocxx::collection coll = db[params.get<std::string>("body.chatID")];
    boost::property_tree::ptree body = params.get_child("body");
    std::stringstream chatInfoStream;
    boost::property_tree::json_parser::write_json(chatInfoStream, body);
    bsoncxx::document::value chatInfoDoc = bsoncxx::from_json(chatInfoStream.str());
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(chatInfoDoc.view());

}

void DataBaseConnector::deleteChat(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db[params.get<std::string>("body.chatID")];
    coll.drop();
}

void DataBaseConnector::deleteUser(boost::property_tree::ptree &params) {
    // TODO: Добавить удаление из всех чатов
    mongocxx::collection coll = db["users"];
    coll.delete_one(document{} << "token" << params.get<std::string>("body.userToken") << finalize);
}

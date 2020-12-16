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

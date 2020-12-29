#ifndef APPLICATION_DATABASECONNECTOR_H
#define APPLICATION_DATABASECONNECTOR_H

#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


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
    explicit DataBaseConnector(std::string &companyName);
    bool userIsRegistered(std::string &token);
    bool userIsAuthorized(std::string &token);
    void authorizeUser(std::string &token);
    void logoutUser(std::string &token);
    void addMessage(boost::property_tree::ptree &params);
    void createChat(boost::property_tree::ptree &params);
    void deleteChat(boost::property_tree::ptree &params);
    void deleteUser(boost::property_tree::ptree &params);
    void createUser(boost::property_tree::ptree &params);
    void getUserInfo(boost::property_tree::ptree &params);
    void getChatInfo(boost::property_tree::ptree &params);
    void logRequest(boost::property_tree::ptree &params);
    void getServerLogs(boost::property_tree::ptree &params);
    std::vector<int> getUserChats(int userId);
    std::string getTeamName(int chatId);
    int getChatMessagesCount(int chatId);
    boost::property_tree::ptree getChatMembers(int chatId);
    void getMessageAuthorInfo(boost::property_tree::ptree &params);
    boost::property_tree::ptree getChatLastMessage(int chatId);
    void getUserChatsPreview(boost::property_tree::ptree &params);
    void getChatMessages(boost::property_tree::ptree &params);
    void makeMessagesInChatChecked(int chatId, int userId);

private:
    mongocxx::uri uri;
    mongocxx::client client;
    mongocxx::database db;
};


template <typename T>
std::vector<T> ptreeVectorToStd(boost::property_tree::ptree const& pt, boost::property_tree::ptree::key_type const& key)
{
    std::vector<T> r;
    for (auto& item : pt.get_child(key))
        r.push_back(item.second.get_value<T>());
    return r;
}
#endif //APPLICATION_DATABASECONNECTOR_H

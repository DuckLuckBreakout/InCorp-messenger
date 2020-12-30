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

/*
 * Adapter for interaction of managers with the database
 */
class DataBaseConnector {
public:
    explicit DataBaseConnector(std::string companyName = std::string("test_company"));

    /*
     * Checking whether the user is registered
     */
    bool userIsRegistered(std::string &token);

    /*
     * Checking whether the user is authorized
     */
    bool userIsAuthorized(std::string &token);

    /*
     * Adding a user to the collection of authorized users
     */
    void authorizeUser(std::string &token);

    /*
     *  Deleting a user from the collection of authorized users
     */
    void logoutUser(std::string &token);

    /*
     * Adding a message to the chat collection
     */
    void addMessage(boost::property_tree::ptree &params);

    /*
     * Create collection for chat
     */
    void createChat(boost::property_tree::ptree &params);

    /*
     * Delete collection for chat
     */
    void deleteChat(boost::property_tree::ptree &params);

    /*
     * Delete user from users collection
     */
    void deleteUser(boost::property_tree::ptree &params);

    /*
     * Add user from users collection
     */
    void createUser(boost::property_tree::ptree &params);

    /*
     * Get user information from users collection
     */
    void getUserInfo(boost::property_tree::ptree &params);

    /*
     * Get chat information from chat collection
     */
    void getChatInfo(boost::property_tree::ptree &params);

    /*
     * Add response to logs collection
     */
    void logRequest(boost::property_tree::ptree &params);

    /*
     * Get documents from logs collection
     */
    void getServerLogs(boost::property_tree::ptree &params);

    /*
     * Get vector of user's chats from users collection
     */
    std::vector<int> getUserChats(int userId);

    /*
     * Get team name from chat collection
     */
    std::string getTeamName(int chatId);

    /*
     * Get messages count from chat collection
     */
    int getChatMessagesCount(int chatId);

    /*
     * Get chats members from chat collection
     */
    boost::property_tree::ptree getChatMembers(int chatId);

    /*
     * Get message author information from users collection
     */
    void getMessageAuthorInfo(boost::property_tree::ptree &params);

    /*
     * Get chat's last message
     */
    boost::property_tree::ptree getChatLastMessage(int chatId);

    /*
     * Get users chats information from users collection
     */
    void getUserChatsPreview(boost::property_tree::ptree &params);

    /*
     * Get chat's messages from chat collection
     */
    void getChatMessages(boost::property_tree::ptree &params);

    /*
     * Change chat's messages status to IsChecked = true
     */
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

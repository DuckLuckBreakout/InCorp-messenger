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
    int chatId = params.get<int>("body.chatId");
    params.put("body.ownerId", params.get<int>("body.ownerId"));
    params.put("body.chatId", params.get<int>("body.chatId"));
    mongocxx::collection coll = db[std::to_string(chatId)];
    boost::property_tree::ptree body = params.get_child("body");
    makeMessagesInChatChecked(chatId, params.get<int>("globalId"));

    int messagesCount = getChatMessagesCount(chatId);
    body.add("number", messagesCount + 1);
    coll.update_one(document{} << "type" << "chat_data" << finalize,
                    document{} << "$set" << open_document << "messages_count" << messagesCount + 1 << close_document << finalize);
    std::stringstream messageStream;
    boost::property_tree::json_parser::write_json(messageStream, body);
    bsoncxx::document::value messageDoc = bsoncxx::from_json(messageStream.str());
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(messageDoc.view());

    params.put_child("chat_members", getChatMembers(chatId));
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
    params.add("body.company", pt.get<std::string>("company"));
    params.add_child("body.chatsId", pt.get_child("chatsId"));

}

void DataBaseConnector::getUserChatsPreview(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db["users"];
    int userId = params.get<int>("globalId");

    params.put_child("body.chats", boost::property_tree::ptree());
    auto &array = params.get_child("body.chats");

    std::vector<int> userChatIds = getUserChats(userId);
    for (int userChatId : userChatIds) {

        boost::property_tree::ptree chat;
        chat.add("chatId", userChatId);
        chat.add("chatName", getTeamName(userChatId));
        array.push_back(std::make_pair("", chat));

    }

}

std::vector<int> DataBaseConnector::getUserChats(int userId) {
    mongocxx::collection coll = db["users"];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "userId" << userId << finalize);
    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);
    std::vector<int> userChats;
    for (auto &chatId : pt.get_child("chatsId")) {
        userChats.push_back(chatId.second.get<int>(""));
    }

    return userChats;
}

boost::property_tree::ptree DataBaseConnector::getChatLastMessage(int chatId) {
    mongocxx::collection coll = db[std::to_string(chatId)];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "type" << "chat_data" << finalize);

    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);

    int lastMessageId = pt.get<int>("messages_count");
    if (lastMessageId) {
        doc = coll.find_one(document{} << "number" << std::to_string(lastMessageId) << finalize);
        std::string docStr1(bsoncxx::to_json(*doc));
        std::istringstream is1((docStr1));
        boost::property_tree::read_json(is1, pt);
        return pt;
    }
    else
        return boost::property_tree::ptree();
}

std::string DataBaseConnector::getTeamName(int chatId) {
    mongocxx::collection coll = db[std::to_string(chatId)];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "type" << "chat_data" << finalize);

    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);

    std::string teamName = pt.get<std::string>("team_name");
    return teamName;
}

void DataBaseConnector::getChatInfo(boost::property_tree::ptree &params) {
    int chatId = params.get<int>("body.chatId");
    mongocxx::collection coll = db[std::to_string(chatId)];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "type" << "chat_data" << finalize);
    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);
    params.add("body.chatName", pt.get<std::string>("team_name"));
    params.add_child("body.usersId", pt.get_child("members_id"));

}

int DataBaseConnector::getChatMessagesCount(int chatId) {
    mongocxx::collection coll = db[std::to_string(chatId)];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "type" << "chat_data" << finalize);
    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);

    return pt.get<int>("messages_count");
}

void DataBaseConnector::getChatMessages(boost::property_tree::ptree &params) {
    int chatId = params.get<int>("body.chatId");
    mongocxx::collection coll = db[std::to_string(chatId)];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "type" << "chat_data" << finalize);
    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);
    int lastMessageId = pt.get<int>("messages_count");
    int userLastMessageId = params.get<int>("body.lastMessageNum");
    makeMessagesInChatChecked(chatId, params.get<int>("globalId"));

    params.put_child("body.messages", boost::property_tree::ptree());
    auto &array = params.get_child("body.messages");

    for (int i = userLastMessageId + 1; i <= lastMessageId; i++) {
        bsoncxx::stdx::optional<bsoncxx::document::value> doc1 = coll.find_one(document{} << "number" << std::to_string(i) << finalize);
//        coll.update_one(document{} << "number" << i << finalize,
//                        document{} << "$set" << open_document << "isChecked" << "true" << close_document << finalize);

        boost::property_tree::ptree pt1;
        std::string docStr1(bsoncxx::to_json(*doc1));
        std::istringstream is1((docStr1));
        boost::property_tree::read_json(is1, pt1);

        array.push_back(std::make_pair("", pt1));
    }
    params.put_child("chat_members", getChatMembers(chatId));

}

void DataBaseConnector::getMessageAuthorInfo(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db["users"];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "userId" << params.get<int>("body.userId") << finalize);
    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);

    params.add("body.firstName", pt.get<std::string>("firstName"));
    params.add("body.lastName", pt.get<std::string>("lastName"));



    params.add("body.role", pt.get<std::string>("team_roles." + std::to_string(params.get<int>("body.chatId"))));
//    for (auto &role : pt.get_child("team_roles")) {
//        params.add("body.role", role.second.get<std::string>(""));
//        break;
//    }
}

void DataBaseConnector::logRequest(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db["0"];
    boost::property_tree::ptree body = params;
    int messagesCount = getChatMessagesCount(0);
    body.add("number", messagesCount + 1);
    coll.update_one(document{} << "type" << "chat_data" << finalize,
                    document{} << "$set" << open_document << "messages_count" << messagesCount + 1 << close_document << finalize);
    std::stringstream messageStream;
    boost::property_tree::json_parser::write_json(messageStream, body);
    bsoncxx::document::value messageDoc = bsoncxx::from_json(messageStream.str());
    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(messageDoc.view());
}

boost::property_tree::ptree DataBaseConnector::getChatMembers(int chatId) {
    mongocxx::collection coll = db[std::to_string(chatId)];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "type" << "chat_data" << finalize);
    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);
    return pt.get_child("members_id");
}

void DataBaseConnector::makeMessagesInChatChecked(int chatId, int userId) {
    mongocxx::collection coll = db[std::to_string(chatId)];
    mongocxx::cursor cursor = coll.find(document{} << "isChecked" << "false" << finalize);
    coll.update_many(document{} << "isChecked" << "false" << "ownerId" << open_document  << "$ne" << std::to_string(userId) << close_document << finalize,
                    document{} << "$set" << open_document << "isChecked" << "true" << close_document << finalize);
}

void DataBaseConnector::getServerLogs(boost::property_tree::ptree &params) {
    mongocxx::collection coll = db["0"];
    bsoncxx::stdx::optional<bsoncxx::document::value> doc = coll.find_one(document{} << "type" << "chat_data" << finalize);
    boost::property_tree::ptree pt;
    std::string docStr(bsoncxx::to_json(*doc));
    std::istringstream is((docStr));
    boost::property_tree::read_json(is, pt);
    int lastMessageId = pt.get<int>("messages_count");
    int userLastMessageId = params.get<int>("body.lastMessageNum");
    if (userLastMessageId == -1)
        userLastMessageId = 0;
    params.put_child("body.logs", boost::property_tree::ptree());
    auto &array = params.get_child("body.logs");

    for (int i = userLastMessageId + 1; i <= lastMessageId; i++) {
        bsoncxx::stdx::optional<bsoncxx::document::value> doc1 = coll.find_one(document{} << "number" << std::to_string(i) << finalize);

        boost::property_tree::ptree pt1;
        std::string docStr1(bsoncxx::to_json(*doc1));
        std::istringstream is1((docStr1));
        boost::property_tree::read_json(is1, pt1);

        array.push_back(std::make_pair("", pt1));
    }
//    params.put_child("chat_members", getChatMembers(chatId));


}


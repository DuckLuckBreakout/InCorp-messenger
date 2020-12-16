#ifndef SERVER_CHATMANAGER_H
#define SERVER_CHATMANAGER_H

#include "BaseManager.h"
#include <boost/property_tree/ptree.hpp>
#include "src/server/lib/Connection/BaseConnection.h"

class ChatManager: public BaseManager {
public:
    ~ChatManager() override = default;

    boost::property_tree::ptree sendMessage(boost::property_tree::ptree &params);
    boost::property_tree::ptree updateChats(boost::property_tree::ptree &params);
    boost::property_tree::ptree deleteChat(boost::property_tree::ptree &params);
    boost::property_tree::ptree createChat(boost::property_tree::ptree &params);
};

#endif //SERVER_CHATMANAGER_H

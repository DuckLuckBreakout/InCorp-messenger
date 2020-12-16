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
    boost::property_tree::ptree command1(boost::property_tree::ptree &params);
    boost::property_tree::ptree command2(boost::property_tree::ptree &params);
    boost::property_tree::ptree command3(boost::property_tree::ptree &params);
    boost::property_tree::ptree command4(boost::property_tree::ptree &params);
    boost::property_tree::ptree command5(boost::property_tree::ptree &params);
    boost::property_tree::ptree command6(boost::property_tree::ptree &params);
    boost::property_tree::ptree command7(boost::property_tree::ptree &params);
    boost::property_tree::ptree command8(boost::property_tree::ptree &params);
};

#endif //SERVER_CHATMANAGER_H

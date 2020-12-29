#ifndef APPLICATION_INFOMANAGER_H
#define APPLICATION_INFOMANAGER_H

#include "BaseManager.h"
#include <boost/property_tree/ptree.hpp>
#include "src/server/lib/Connection/BaseConnection.h"

class InfoManager: public BaseManager {
public:
    ~InfoManager() override = default;
    boost::property_tree::ptree getMessageAuthorInfo(boost::property_tree::ptree &params);
    boost::property_tree::ptree getChatInfo(boost::property_tree::ptree &params);
    boost::property_tree::ptree getUserChatsPreview(boost::property_tree::ptree &params);

};


#endif //APPLICATION_INFOMANAGER_H

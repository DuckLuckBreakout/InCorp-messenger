#include <boost/property_tree/ptree.hpp>
#include "Controller.h"


Controller::Controller() :
                           authorizationManager(new AuthorizationManager) {

}

boost::property_tree::ptree Controller::loginUser(boost::property_tree::ptree &params) {
    return authorizationManager->loginUser(params);
}

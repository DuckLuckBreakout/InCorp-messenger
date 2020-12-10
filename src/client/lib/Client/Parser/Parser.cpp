#include <iostream>
#include "Parser.h"

void Parser::clear() {
    tree.clear();
}

std::string Parser::getJson() {
    std::stringstream result;
    boost::property_tree::write_json(result, tree);

    std::string resultStr = result.str();
    boost::algorithm::replace_all(resultStr, "\"[]\"", "[]");
    return resultStr;
}

void Parser::setJson(const std::string& jsonStr) {
    this->clear();

    std::stringstream jsonData(jsonStr);
    boost::property_tree::read_json(jsonData, tree);
}


void Parser::addJsonStr(const std::string &json, const std::string &name) {
    boost::property_tree::ptree tmpTree;
    std::stringstream ss(json);
    boost::property_tree::read_json(ss, tmpTree);

    tree.add_child(name, tmpTree);
}

void Parser::addArrayJsonStr(const std::vector<std::string> &jsonStr,
                          const std::string &name) {
    boost::property_tree::ptree tmpTree;
    if (jsonStr.empty())
        tmpTree.put("", "[]");

    for (const auto& value : jsonStr) {
        boost::property_tree::ptree elem;
        std::stringstream stream(value);
        boost::property_tree::read_json(stream, elem);
        tmpTree.push_back(make_pair("", elem));
    }

    tree.add_child(name, tmpTree);
}

std::string Parser::getJsonStr(const std::string &name) {
    std::stringstream stream;
    boost::property_tree::write_json(stream, tree.get_child(name));

    return stream.str();
}

std::vector<std::string> Parser::getArrayJsonStr(const std::string& name) {
    std::vector<std::string> result;
    for (const auto& item : tree.get_child(name)) {
        std::stringstream stream;
        boost::property_tree::write_json(stream, item.second);
        result.push_back(stream.str());
    }

    return result;
}




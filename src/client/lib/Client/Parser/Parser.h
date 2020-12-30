#ifndef APPLICATION_PARSER_H
#define APPLICATION_PARSER_H

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string/replace.hpp>


// JSON parser
class Parser {
public:
    // Add template value
    template <typename T>
    void addValue(T& value, const std::string& name) {
        tree.put(name, value);
    }

    // Get template value
    template <typename T>
    T getValue(const std::string& name) {
        return tree.get<T>(name);
    }

    // Add template array
    template <typename T>
    void addArray(const std::vector<T>& vector, const std::string& name) {
        boost::property_tree::ptree tmpTree;
        if (vector.empty())
            tmpTree.put("", "[]");

        for (const auto& value : vector) {
            boost::property_tree::ptree element;
            element.put("", value);
            tmpTree.push_back(std::make_pair("", element));
        }
        tree.add_child(name, tmpTree);
    };

    // Get template array
    template <typename T>
    std::vector<T> getArray(const std::string& name) {
        std::vector<T> result;
        for (const auto& value : tree.get_child(name)) {
            auto tmpValue = value.second.get_value_optional<T>();
            if (tmpValue)
                result.push_back(tmpValue.value());
        }

        return result;
    };

    // Set JSON string for parsing
    void setJson(const std::string& jsonStr);

    // Get JSON string
    std::string getJson();
    
    // Add JSON str
    void addJsonStr(const std::string &json, const std::string &name);
    
    // Add JSON array
    void addArrayJsonStr(const std::vector<std::string> &jsonStr, const std::string &name);
    
    // Get JSON str
    std::string getJsonStr(const std::string &name);
    
    // Get JSON array
    std::vector<std::string> getArrayJsonStr(const std::string& name);

    void clear();

private:
    boost::property_tree::ptree tree;
};


#endif //APPLICATION_PARSER_H

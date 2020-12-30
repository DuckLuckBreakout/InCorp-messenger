#ifndef APPLICATION_USERDATA_H
#define APPLICATION_USERDATA_H

#include <memory>
#include <vector>
#include <map>


// Data of current user
class UserData {
public:
    static std::shared_ptr<UserData> getInstance() {
        static std::shared_ptr<UserData> userData(new UserData);
        return userData;
    };

private:
    UserData() = default;

public:
    std::string firstName;
    std::string lastName;
    int userId = -1;
    std::string role;
    std::vector<int> chatsId;
    std::string company;
    int currentChatId = -1;
};


#endif //APPLICATION_USERDATA_H

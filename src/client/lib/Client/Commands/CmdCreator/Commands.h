#ifndef APPLICATION_COMMANDS_H
#define APPLICATION_COMMANDS_H

// System code of command
enum Commands {
    ChatObserver = -2,
    SystemUpdate = -1,
    LogIn = 0,
    SendMessage = 1,
    GetListOfChats = 20,
    GetSelectChatRoom = 21,
    GetMessagesInChat = 22,
    GetLastMessageInChat = 23,
    GetUserData = 24,
    GetLog = 25,
    SendChatCommand = 26,
    RegistrationUser = 27,
};


#endif //APPLICATION_COMMANDS_H

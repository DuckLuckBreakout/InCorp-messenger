#ifndef APPLICATION_CONTROLLER_H
#define APPLICATION_CONTROLLER_H

#include <stdlib.h>
#include <functional>
#include <optional>

#include "ChatObjects/ChatUpdates.h"
#include "Commands/CmdCreator/Commands.h"
#include "Client/Client.h"
#include "Commands/CmdCreator/CommandCreator.h"
#include "UserOptions/BaseUserOptions.h"
#include "UserOptions/GuestOptions.h"
#include "RoleController/RoleController.h"
#include <ChatObjects/ChatRoom.h>


// Facade of client lib
class Controller: public std::enable_shared_from_this<Controller> {
public:
    static std::shared_ptr<Controller> getInstance();
    Controller(const Controller &controller) = delete;
    Controller(Controller &&controller) = delete;
    Controller& operator=(const Controller &controller) = delete;
    Controller& operator=(Controller &&controller) = delete;
    ~Controller() = default;

    // Run client connection
    void runClient(const std::string& ip, const std::string& port,
                   const std::function<void(int)>& errHandler);
    
    // Reconnect client connection
    void reconnectClient(const std::string& ip, const std::string& port);

    // Send message in select chat
    void sendMessage(const Message& message, int globalId,
                     const std::shared_ptr<BaseCallback>& callback);

    // Authorization user
    void authorization(const UserInfo& authInfo, int globalId,
                       const std::shared_ptr<BaseCallback>& callback);

    // Update select chat
    void chatUpdate(const ChatUpdates& chatUpdates, int globalId,
                    const std::shared_ptr<BaseCallback>& callback);

    // Get list of chats
    void getListChats(const ListChats& listChats, int globalId,
                      const std::shared_ptr<BaseCallback>& callback);

    // Get select chat room
    void getChatRoom(const ChatRoom& chatRoom, int globalId,
                     const std::shared_ptr<BaseCallback>& callback);

    // Get messages in select chat
    void getChatMessages(const ChatUpdates& chatUpdates, int globalId,
                        const std::shared_ptr<BaseCallback>& callback);

    // Get log
    void getLog(const LogUpdates& logUpdates, int globalId,
                const std::shared_ptr<BaseCallback>& callback);

    // Get last message in chat
    void getLastMessage(const Message& message, int globalId,
                        const std::shared_ptr<BaseCallback>& callback);

    // Get user 
    void getUser(const UserPreview& user, int globalId,
                 const std::shared_ptr<BaseCallback>& callback);

    // Set chat observer
    void setChatObserver(int chatId, const std::shared_ptr<BaseCallback>& callback);

    // Message handler 
    void readMessageHandler(const std::string& str);

    // Send chat command
    void sendChatCommand(const Message& message, int globalId);

    // Registration new user
    void registration(const UserInfo& authInfo, int globalId,
                      const std::shared_ptr<BaseCallback>& callback);

private:
    Controller();

private:
    std::shared_ptr<Client> client;
    std::shared_ptr<CallbacksHolder> callbackHolder;
    std::shared_ptr<BaseUserOptions> userOptions;
};


#endif //APPLICATION_CONTROLLER_H

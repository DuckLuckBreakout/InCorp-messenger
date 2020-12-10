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

class Controller: public std::enable_shared_from_this<Controller> {
public:
    static std::shared_ptr<Controller> getInstance();
    Controller(const Controller &controller) = delete;
    Controller(Controller &&controller) = delete;
    Controller& operator=(const Controller &controller) = delete;
    Controller& operator=(Controller &&controller) = delete;
    ~Controller() = default;

    void runClient(const std::string& ip, const std::string& port,
                   const std::function<void(int)>& errHandler);
    void reconnectClient(const std::string& ip, const std::string& port);

    void sendMessage(const Message& message, int globalId,
                     const std::shared_ptr<BaseCallback>& callback);

    void authorization(const Authorization& authInfo, int globalId,
                       const std::shared_ptr<BaseCallback>& callback);


    void chatUpdate(const ChatUpdates& chatUpdates, int globalId,
                    const std::shared_ptr<BaseCallback>& callback);

    void readMessageHandler(const std::string& str);

private:
    Controller();

private:
    std::shared_ptr<Client> client;
    std::shared_ptr<CallbacksHolder> callbackHolder;
    std::shared_ptr<BaseUserOptions> userOptions;
};


#endif //APPLICATION_CONTROLLER_H

<h1 align="center">InCorp Messenger</h1>

<p align="center">
  
[![Build Status](https://travis-ci.com/vaderoi/InCorp-messenger.svg?branch=main)](https://travis-ci.com/vaderoi/InCorp-messenger)

</p>

## The main problems to be solved

- Separation of personal and work space
- Isolation of company data
- Control of employee actions
- Separation of roles
  - company
  - manager
  - employee
- Ability to configure business logic for a specific company
- Private access to the company's messenger

## Presentation

<p align="center">
<img src="https://media.giphy.com/media/MZS7jILH8igpe4lP2p/giphy.gif">
</p>

## Code statistic
```bash
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                             90            867             49           3883
C/C++ Header                    99            786            441           2248
Qt                               5              0              0           2194
CMake                            7            144            138            652
Markdown                         1             29              0            153
Dockerfile                       1             23              0             49
Bourne Shell                     1              8              0             18
YAML                             1              7              6             14
-------------------------------------------------------------------------------
SUM:                           205           1864            634           9211
-------------------------------------------------------------------------------
```

## Coverage
```bash
                                       |Lines       |Functions  |Branches    
Filename                               |Rate     Num|Rate    Num|Rate     Num
=============================================================================
[/googletest-src/googlemock/include/gmock/]
gmock-actions.h                        |84.0%     25|87.1%    62|    -      0
gmock-cardinalities.h                  | 100%      2| 100%     1|    -      0
gmock-function-mocker.h                | 100%      2| 100%     7|    -      0
gmock-matchers.h                       |29.3%     41|46.7%    45|    -      0
gmock-spec-builders.h                  |51.5%    274|63.5%   340|    -      0

[/googletest-src/googlemock/include/gmock/internal/]
gmock-internal-utils.h                 |30.0%     10| 5.9%    17|    -      0

[/googletest-src/googletest/include/gtest/]
gtest-matchers.h                       |72.7%     22|72.7%    55|    -      0
gtest-printers.h                       | 0.0%     61| 0.0%    40|    -      0
gtest.h                                |28.6%      7|16.7%     6|    -      0

[/googletest-src/googletest/include/gtest/internal/]
gtest-internal.h                       |89.5%     19|97.7%    44|    -      0
gtest-port.h                           |94.1%     34|94.1%    17|    -      0

[/src/server/Tests/]
test.cpp                               | 100%      3| 100%     1|    -      0

[/src/server/lib/CompanyServer/MainServerLogic/MainLogic/]
Controller/Controller.h                | 100%      1| 100%     1|    -      0
Managers/AuthorizationManager.h        | 100%      1| 100%     2|    -      0
Managers/BaseManager.h                 | 100%      2|66.7%     3|    -      0
Managers/CommandsManager.h             | 100%      1| 100%     2|    -      0
Managers/InfoManager.h                 | 100%      1| 100%     2|    -      0
Managers/LogsManager.h                 | 100%      1| 100%     2|    -      0
Managers/RegistrationManager.h         | 100%      1| 100%     2|    -      0

[/src/server/lib/CompanyServer/Tests/]
gmockTests.cpp                         | 100%    254| 100%   259|    -      0
=============================================================================
                                 Total:|67.3%    762|74.1%   908|    -      0
```

```bash
                                               |Lines      |Functions|Branches  
Filename                                       |Rate    Num|Rate  Num|Rate   Num
================================================================================
[/googletest-src/googlemock/include/gmock/]
gmock-actions.h                                |84.0%    25|83.7%  86|    -    0
gmock-cardinalities.h                          | 100%     2| 100%   1|    -    0
gmock-function-mocker.h                        | 100%     2| 100%  12|    -    0
gmock-matchers.h                               |29.3%    41|49.0% 155|    -    0
gmock-spec-builders.h                          |51.5%   274|63.7% 556|    -    0

[/googletest-src/googlemock/include/gmock/internal/]
gmock-internal-utils.h                         |30.0%    10| 3.4%  29|    -    0

[/googletest-src/googletest/include/gtest/]
gtest-matchers.h                               |75.0%    24|74.6% 169|    -    0
gtest-message.h                                | 0.0%     3| 0.0%   2|    -    0
gtest-printers.h                               | 0.0%    85| 0.0% 234|    -    0
gtest.h                                        |42.1%    19|61.1%  72|    -    0

[/googletest-src/googletest/include/gtest/internal/]
gtest-internal.h                               |90.5%    21|99.2% 122|    -    0
gtest-port.h                                   |94.1%    34|94.1%  17|    -    0
gtest-type-util.h                              | 0.0%    13| 0.0%   2|    -    0

[/src/]
client/lib/Client/Call...allback/BaseCallback.h| 100%     3| 100%   2|    -    0
client/lib/Client/Call...lder/CallbacksHolder.h| 100%    20| 100%   3|    -    0
client/lib/Client/ChatObjects/BaseObject.h     | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/ChatAction.h     | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/ChatItem.h       | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/ChatRoom.h       | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/ChatUpdates.h    | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/ListChats.h      | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/Log.h            | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/LogUpdates.h     | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/Message.h        | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/MessageStatus.h  | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/Request.h        | 100%     1|50.0%   2|    -    0
client/lib/Client/ChatObjects/UserPreview.h    | 100%     1|50.0%   2|    -    0
client/lib/Client/Client/BaseClient.h          | 100%     1|50.0%   2|    -    0
client/lib/Client/Client/Client.h              | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/AuthorizationCmd.h  | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/BaseCmd.h           | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/ChatObserverCmd.h   | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/ChatUpdateCmd.h     | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/GetChatMessagesCmd.h| 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/GetChatRoomCmd.h    | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/GetLastMessageCmd.h | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/GetListChatsCmd.h   | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/GetLogCmd.h         | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/GetUserCmd.h        | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/RegistrationCmd.h   | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/SendMessageCmd.h    | 100%     1|50.0%   2|    -    0
client/lib/Client/Commands/SystemUpdateCmd.h   | 100%     1|50.0%   2|    -    0
client/lib/Client/Parser/Parser.h              |95.5%    22| 100%  10|    -    0
client/lib/Client/UserOptions/BaseUserOptions.h| 100%     1|50.0%   2|    -    0
client/lib/Client/UserOptions/CompanyOptions.h | 100%     1|50.0%   2|    -    0
client/lib/Client/UserOptions/EmployeeOptions.h| 100%     1|50.0%   2|    -    0
client/lib/Client/UserOptions/GuestOptions.h   | 100%     1|50.0%   2|    -    0
client/lib/Client/UserOptions/ManagerOptions.h | 100%     1|50.0%   2|    -    0
client/test/gmock.cpp                          | 100%    88|97.7%  86|    -    0
client/test/gtest.cpp                          | 100%   326| 100% 256|    -    0
client/test/test.cpp                           | 100%     3| 100%   1|    -    0
server/Tests/test.cpp                          | 100%     3| 100%   1|    -    0
server/lib/CompanyServ...ontroller/Controller.h| 100%     1| 100%   1|    -    0
server/lib/CompanyServ...AuthorizationManager.h| 100%     1| 100%   2|    -    0
server/lib/CompanyServ...Managers/BaseManager.h| 100%     2|66.7%   3|    -    0
server/lib/CompanyServ...gers/CommandsManager.h| 100%     1| 100%   2|    -    0
server/lib/CompanyServ...Managers/InfoManager.h| 100%     1| 100%   2|    -    0
server/lib/CompanyServ...Managers/LogsManager.h| 100%     1| 100%   2|    -    0
server/lib/CompanyServ.../RegistrationManager.h| 100%     1| 100%   2|    -    0
server/lib/CompanyServer/Tests/gmockTests.cpp  | 100%   254| 100% 259|    -    0
================================================================================
                                         Total:|77.4%  1312|68.9%  2k|    -    0
```


## Events Emitted

| Name       | Type   | Task                             | Status |
| ---------- | ------ | -------------------------------- | ------ |
| `pre-defense` | RK | MVP |  :heavy_check_mark:  |
| `protection` | RK | Present project |  :heavy_check_mark:  |

## Team - DuckLuck

__students:__

:mortar_board: [Ivan Kovalenko](https://github.com/DuckLuckBreakout)

:mortar_board: [Nikita Suvorov](https://github.com/Tullerpeton?tab=repositories) 

__mentor:__

[Ilya Saneev](https://github.com/IlyaSaneev)

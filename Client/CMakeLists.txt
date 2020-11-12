cmake_minimum_required(VERSION 3.17)
project(Client)

set(CMAKE_CXX_STANDARD 17)


add_library(Client STATIC
        Client.cpp
        UserOptions/ManagerOptions.cpp
        UserOptions/EmployeeOptions.cpp
        UserOptions/GuestOptions.cpp
        Manager/ChatManager.cpp
        Manager/AuthorizationManager.cpp
        RoleController/RoleController.cpp
        ../src/libs/Connection/HttpConnection.cpp
        ../src/libs/Connection/Coder/HttpCoder.cpp
        )

target_include_directories(Client PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)
target_link_libraries(Client -lboost_system -lpthread -std=c++17)

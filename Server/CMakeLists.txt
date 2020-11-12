cmake_minimum_required(VERSION 3.17)
project(Server)

set(CMAKE_CXX_STANDARD 17)


add_library(Server STATIC
        Server.cpp
        Server/HttpServer.cpp
        MainServerLogic/CommandHandler/CommandHandler.cpp
        MainServerLogic/CommandCreator/CommandCreator.cpp
        MainServerLogic/Commands/Login.cpp
        MainServerLogic/Commands/Logout.cpp
        MainServerLogic/Commands/UpdateChats.cpp
        MainServerLogic/Commands/WriteMessage.cpp
        MainServerLogic/MainLogic/MainLogic.cpp
        MainServerLogic/MainLogic/Controller/Controller.cpp
        MainServerLogic/MainLogic/Managers/AuthorizationManager.cpp
        MainServerLogic/MainLogic/Managers/ChatManager.cpp
        MainServerLogic/MainLogic/Managers/DataBaseManager.cpp
        ../src/libs/Connection/HttpConnection.cpp
        ../src/libs/Connection/Coder/HttpCoder.cpp
        )



target_include_directories(Server PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)
target_link_libraries(Server
        #-lboost_system
        -lpthread
        -std=c++17)
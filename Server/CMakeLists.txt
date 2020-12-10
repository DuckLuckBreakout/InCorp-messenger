cmake_minimum_required(VERSION 3.16)
project(Server)

set(CMAKE_CXX_STANDARD 17)


add_library(Server STATIC
        Server/HttpServer.cpp
        MainServerLogic/CommandHandler/CommandHandler.cpp
        MainServerLogic/CommandCreator/CommandCreator.cpp
        MainServerLogic/Commands/Login.cpp
        MainServerLogic/Commands/Logout.cpp
        MainServerLogic/Commands/UpdateChats.cpp
        MainServerLogic/Commands/WriteMessage.cpp
        MainServerLogic/Commands/CreateChat.cpp
        MainServerLogic/Commands/DeleteChat.cpp
        MainServerLogic/Commands/DeleteUser.cpp
        MainServerLogic/Commands/CreateUser.cpp
        MainServerLogic/MainLogic/MainLogic.cpp
        MainServerLogic/MainLogic/Controller/Controller.cpp
        MainServerLogic/MainLogic/Managers/AuthorizationManager.cpp
        MainServerLogic/MainLogic/Managers/ChatManager.cpp
        MainServerLogic/DataBaseConnector/DataBaseConnector.cpp
        ../src/libs/Connection/HttpConnection.cpp
        ../src/libs/Connection/Coder/HttpCoder.cpp
        )


if (APPLE)
    target_include_directories(Server PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)
    target_link_libraries(Server
            #-lboost_system
            -lpthread
            -std=c++17)

elseif (UNIX)
    target_include_directories(Server PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)
    target_link_libraries(Server
            -lboost_system
            -lpthread
            -std=c++17)
endif()
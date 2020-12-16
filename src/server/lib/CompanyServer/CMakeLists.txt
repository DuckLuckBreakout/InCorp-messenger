cmake_minimum_required(VERSION 3.16)
project(ServerApp)

set(CMAKE_CXX_STANDARD 17)


add_library(ServerApp STATIC
        Server/Server.cpp
        Server/WorkerThread.cpp
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
        MainServerLogic/Commands/Command1.cpp
        MainServerLogic/Commands/Command2.cpp
        MainServerLogic/Commands/Command3.cpp
        MainServerLogic/Commands/Command4.cpp
        MainServerLogic/Commands/Command5.cpp
        MainServerLogic/Commands/Command6.cpp
        MainServerLogic/Commands/Command7.cpp
        MainServerLogic/Commands/Command8.cpp
        MainServerLogic/MainLogic/MainLogic.cpp
        MainServerLogic/MainLogic/Controller/Controller.cpp
        MainServerLogic/MainLogic/Managers/AuthorizationManager.cpp
        MainServerLogic/MainLogic/Managers/ChatManager.cpp
        MainServerLogic/DataBaseConnector/DataBaseConnector.cpp
        ../Connection/HttpConnection.cpp
        )


if (APPLE)
    target_include_directories(ServerApp PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)
    target_link_libraries(ServerApp
            #-lboost_system
            -lpthread
            -std=c++17)

elseif (UNIX)
    target_include_directories(ServerApp PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)
    target_link_libraries(ServerApp
            -lboost_system
            -lpthread
            -std=c++17)
endif()
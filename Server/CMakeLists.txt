cmake_minimum_required(VERSION 3.17)
set(PROJECT server)
project(${PROJECT})
set(CMAKE_CXX_STANDARD 17)

set(SOURCES


        Connection/Coders/BaseCoder.cpp
        Connection/Coders/HttpCoder.cpp
        Connection/ConnectionCreators/BaseConnectionCreator.cpp
        Connection/ConnectionCreators/HttpConnectionCreator.cpp
        Connection/Connections/BaseConnection.cpp
        Connection/Connections/HttpConnection.cpp

        MainServerLogic/CommandHandler/CommandHandler.cpp
        MainServerLogic/CommandParser/CommandCreator.cpp
        MainServerLogic/Commands/UpdateChats.cpp
        MainServerLogic/Commands/WriteMessage.cpp
        MainServerLogic/MainLogic/Controller/Controller.cpp
        MainServerLogic/MainLogic/Managers/DataBaseManager.cpp
        MainServerLogic/MainLogic/MainLogic.cpp

        Server/HttpServer.cpp
        )


set(BOOST_ROOT "/usr/local/Cellar/boost/1.74.0")

find_package(Boost 1.74.0 COMPONENTS system filesystem REQUIRED)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Boost_LIBRARIES})
include_directories(${BOOST_ROOT})

add_executable(${PROJECT} main.cpp ${SOURCES})
target_link_libraries(${PROJECT} -lpthread -std=c++17)
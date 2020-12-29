#cmake_minimum_required(VERSION 3.2)
#set(PROJECT_NAME Application)
#
#project(${PROJECT_NAME})
#set(CMAKE_CXX_STANDARD 17)
#
#if (APPLE)
#    message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
#    set(libmongocxx_DIR "/opt/mongo-cxx-driver/lib/cmake/libmongocxx-3.6.2/")
#    set(libbsoncxx_DIR "/opt/mongo-cxx-driver/lib/cmake/libbsoncxx-3.6.2/")
#    find_package(libmongocxx REQUIRED)
#    find_package(libbsoncxx REQUIRED)
#    message("LIBMONGOCXX_INCLUDE_DIRS = ${LIBMONGOCXX_INCLUDE_DIRS}")
#    message("LIBMONGOCXX_LIBRARIES = ${LIBMONGOCXX_LIBRARIES}")
#    message("LIBBSONCXX_INCLUDE_DIRS = ${LIBBSONCXX_INCLUDE_DIRS}")
#    message("LIBBSONCXX_LIBRARIES = ${LIBBSONCXX_LIBRARIES}")
#
#    include_directories("/opt/mongo-cxx-driver/include/mongocxx/v_noabi")
#    include_directories("/opt/mongo-cxx-driver/include/bsoncxx/v_noabi")
#    include_directories("/usr/local/include/libmongoc-1.0")
#    include_directories("/usr/local/include/libbson-1.0")
#    include_directories("/opt/mongo-cxx-driver/lib/cmake/")
#    include_directories("/usr/local/include/mongocxx/v_noabi")
#    include_directories("/usr/local/include/bsoncxx/v_noabi")
#    include_directories("/usr/local/include/libmongoc-1.0")
#    include_directories("/usr/local/include/libbson-1.0")
#    include_directories("/usr/local/lib")
#
#    set(BOOST_ROOT "/usr/local/Cellar/boost/1.74.0")
#
#    find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
#    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
#    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
#
#    set(DEBUG_CXX_FLAGS "-std=c++17 -pthread -g3 -lboost_thread-mt")
#
#elseif(UNIX)
#    set(BOOST_ROOT "boost")
#    find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
#    message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
##    set(libmongocxx_DIR "${CMAKE_BINARY_DIR}opt/mongo-cxx-driver/lib/cmake/libmongocxx-3.6.2/")
##    set(libbsoncxx_DIR "${CMAKE_BINARY_DIR}opt/mongo-cxx-driver/lib/cmake/libbsoncxx-3.6.2/")
##    find_package(libmongocxx REQUIRED)
##    find_package(libbsoncxx REQUIRED)
##    message("LIBMONGOCXX_INCLUDE_DIRS = ${LIBMONGOCXX_INCLUDE_DIRS}")
##    message("LIBMONGOCXX_LIBRARIES = ${LIBMONGOCXX_LIBRARIES}")
##    message("LIBBSONCXX_INCLUDE_DIRS = ${LIBBSONCXX_INCLUDE_DIRS}")
##    message("LIBBSONCXX_LIBRARIES = ${LIBBSONCXX_LIBRARIES}")
##    include_directories("/opt/mongo-cxx-driver/include/mongocxx/v_noabi")
##    include_directories("/opt/mongo-cxx-driver/include/bsoncxx/v_noabi")
##    include_directories("/usr/local/include/libmongoc-1.0")
##    include_directories("/usr/local/include/libbson-1.0")
##    include_directories("/opt/mongo-cxx-driver/lib/cmake/")
##    include_directories("/opt/mongo-cxx-driver/lib/libbsoncxx.so._noabi")
##    include_directories("/usr/local/include/mongocxx/v_noabi")
##    include_directories("/usr/local/include/bsoncxx/v_noabi")
##    include_directories("/usr/local/include/libmongoc-1.0")
##    include_directories("/usr/local/include/libbson-1.0")
##    include_directories("/usr/local/lib")
#    option(${PROJECT_NAME}_SUPERBUILD "Build ${PROJECT_NAME} and the projects it depends on." ON)
#
#    include(ExternalProject)
#
#    set(common_cmake_cache_args
#            -DCMAKE_CXX_COMPILER:PATH=${CMAKE_CXX_COMPILER}
#            )
#    if(NOT DEFINED CMAKE_CONFIGURATION_TYPES)
#        list(APPEND common_cmake_cache_args
#                -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
#                )
#    endif()
#
#    ExternalProject_Add(libmongoc
#            GIT_REPOSITORY  "https://github.com/mongodb/mongo-c-driver.git"
#            GIT_TAG         "1.12.0"
#            GIT_PROGRESS    1
#            GIT_SHALLOW     1
#            SOURCE_DIR      "${CMAKE_BINARY_DIR}/libmongoc"
#            BINARY_DIR      "${CMAKE_BINARY_DIR}/libmongoc-build"
#            INSTALL_DIR     "${CMAKE_BINARY_DIR}/libmongoc-install"
#            CMAKE_CACHE_ARGS
#            ${common_cmake_cache_args}
#            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/libmongoc-install
#            -DENABLE_TESTS:BOOL=OFF
#            -DENABLE_STATIC:BOOL=OFF
#            -DENABLE_EXAMPLES:BOOL=OFF
#            -DENABLE_EXTRA_ALIGNMENT:BOOL=OFF
#            #INSTALL_COMMAND ""
#            )
#    set(libmongoc-1.0_DIR "${CMAKE_BINARY_DIR}/libmongoc-install/lib/cmake/libmongoc-1.0/")
#    set(libbson-1.0_DIR "${CMAKE_BINARY_DIR}/libmongoc-install/lib/cmake/libbson-1.0/")
#
#    ExternalProject_Add(libmongocxx
#            GIT_REPOSITORY  "https://github.com/mongodb/mongo-cxx-driver.git"
#            GIT_TAG         "r3.3.1"
#            GIT_PROGRESS    1
#            GIT_SHALLOW     1
#            SOURCE_DIR      "${CMAKE_BINARY_DIR}/libmongocxx"
#            BINARY_DIR      "${CMAKE_BINARY_DIR}/libmongocxx-build"
#            INSTALL_DIR     "${CMAKE_BINARY_DIR}/libmongocxx-install"
#            CMAKE_CACHE_ARGS
#            ${common_cmake_cache_args}
#            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/libmongocxx-install
#            -DBUILD_SHARED_LIBS:BOOL=ON
#            -DENABLE_TESTS:BOOL=OFF
#            -DENABLE_EXAMPLES:BOOL=OFF
#            -DBSONCXX_POLY_USE_BOOST:BOOL=OFF
#            -DBSONCXX_POLY_USE_MNMLSTC:BOOL=ON
#            -DBSONCXX_POLY_USE_STD:BOOL=OFF
#            -Dlibmongoc-1.0_DIR:PATH=${libmongoc-1.0_DIR}
#            -Dlibbson-1.0_DIR:PATH=${libbson-1.0_DIR}
#            DEPENDS
#            libmongoc
#            )
#    set(libmongocxx_DIR "${CMAKE_BINARY_DIR}/libmongocxx-install/lib/cmake/libmongocxx-3.3.1/")
#    set(libbsoncxx_DIR "${CMAKE_BINARY_DIR}/libmongocxx-install//lib/cmake/libbsoncxx-3.3.1/")
#
#
#    function(ExternalProject_AlwaysConfigure proj)
#        # This custom external project step forces the configure and later
#        # steps to run.
#        _ep_get_step_stampfile(${proj} "configure" stampfile)
#        ExternalProject_Add_Step(${proj} forceconfigure
#                COMMAND ${CMAKE_COMMAND} -E remove ${stampfile}
#                COMMENT "Forcing configure step for '${proj}'"
#                DEPENDEES build
#                ALWAYS 1
#                )
#    endfunction()
#
#    ExternalProject_Add(${PROJECT_NAME}
#            SOURCE_DIR "${CMAKE_SOURCE_DIR}"
#            BINARY_DIR "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-build"
#            DOWNLOAD_COMMAND ""
#            UPDATE_COMMAND ""
#            CMAKE_CACHE_ARGS
#            ${common_cmake_cache_args}
#            -D${PROJECT_NAME}_SUPERBUILD:BOOL=OFF
#            -Dlibbsoncxx_DIR:PATH=${libbsoncxx_DIR}
#            -Dlibmongocxx_DIR:PATH=${libmongocxx_DIR}
#            INSTALL_COMMAND ""
#            DEPENDS
#            libmongocxx
#            )
#    ExternalProject_AlwaysConfigure(${PROJECT_NAME})
#    set(DEBUG_CXX_FLAGS "-std=c++17 -pthread -g3 -lboost_thread")
#    return()
#
#endif()
#find_package(libmongocxx REQUIRED)
#
#if(NOT Boost_FOUND)
#    message(FATAL_ERROR "Could not find boost!")
#endif()
#message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
#message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
#message(STATUS "Boost_VERSION: ${Boost_VERSION}")
#include_directories(${Boost_INCLUDE_DIRS})
#include_directories(${Boost_LIBRARIES})
#include_directories(${BOOST_ROOT})
#
## ---------- Compiling flags ----------
## Release flags
#set(RELEASE_CXX_FLAGS "-std=c++17 -Wall -Werror -pedantic")
#set(RELEASE_C_FLAGS "-std=c99 -Wall -Werror -pedantic")
## Debug flags
##set(DEBUG_CXX_FLAGS "-std=c++17 -pthread -g3 -lboost_thread-mt")
#set(DEBUG_C_FLAGS "-std=c99 -pthread -g3")
#
#
## -------- Build lib ---------
#add_subdirectory(src/server/lib/CompanyServer)
#
#
## ---------- Build target -----------
#message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
#if (CMAKE_BUILD_TYPE MATCHES Debug)
#    # Set flags
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_CXX_FLAGS}")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_C_FLAGS}")
#
#    add_executable (${PROJECT_NAME}
#            main.cpp
#            )
#
#    target_link_libraries(${PROJECT_NAME}
#            ServerApp
#            ${LIBMONGOCXX_LIBRARIES}
##            ${LIBBSONCXX_LIBRARIES}
#            )
#
#elseif (CMAKE_BUILD_TYPE MATCHES Test)
#
#    if (CMAKE_VERSION VERSION_LESS 3.2)
#        set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
#    else()
#        set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
#    endif()
#
#
#    include(config/gtest/DownloadProject.cmake)
#    download_project(PROJ                googletest
#            GIT_REPOSITORY      https://github.com/google/googletest.git
#            GIT_TAG             master
#            ${UPDATE_DISCONNECTED_IF_AVAILABLE}
#            )
#
#    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#
#    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
#
#    if (CMAKE_VERSION VERSION_LESS 2.8.11)
#        include_directories("${gtest_SOURCE_DIR}/include"
#                "${gmock_SOURCE_DIR}/include")
#    endif()
#
#    # Set flags
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_C_FLAGS} -fprofile-arcs -ftest-coverage")
#
#
#    add_executable(${PROJECT_NAME}
#            src/server/lib/CompanyServer/Tests/gmockTests.cpp
#            src/server/Tests/test.cpp
#            )
#
#    target_link_libraries(${PROJECT_NAME}
#            gtest
#            gmock_main
##            gcov
#            ServerApp
#            ${LIBMONGOCXX_LIBRARIES}
#            ${LIBBSONCXX_LIBRARIES}
#            )
#
#    add_test(run_tests run_tests)
#
#elseif (CMAKE_BUILD_TYPE MATCHES Release)
#    # Set flags
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${RELEASE_CXX_FLAGS}")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${RELEASE_C_FLAGS}")
#
#    add_executable (${PROJECT_NAME}
#            main.cpp
#            )
#
#    target_link_libraries(${PROJECT_NAME}
#            ServerApp
#            )
#
#endif ()
#
#
#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR} ${LIBMONGOCXX_INCLUDE_DIRS})
#target_compile_definitions(${PROJECT_NAME} PUBLIC ${LIBMONGOCXX_DEFINITIONS})

#cmake_minimum_required(VERSION 3.2)
#
#set(CMAKE_CXX_STANDARD 17)
#set(PROJECT_NAME Application)
#project(${PROJECT_NAME})
#
#option(${PROJECT_NAME}_SUPERBUILD "Build ${PROJECT_NAME} and the projects it depends on." ON)
#
#if(${PROJECT_NAME}_SUPERBUILD)
#
#    include(ExternalProject)
#
#    set(common_cmake_cache_args
#            -DCMAKE_CXX_COMPILER:PATH=${CMAKE_CXX_COMPILER}
#            )
#    if(NOT DEFINED CMAKE_CONFIGURATION_TYPES)
#        list(APPEND common_cmake_cache_args
#                -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
#                )
#    endif()
#
#    ExternalProject_Add(libmongoc
#            GIT_REPOSITORY  "https://github.com/mongodb/mongo-c-driver.git"
#            GIT_TAG         "1.12.0"
#            GIT_PROGRESS    1
#            GIT_SHALLOW     1
#            SOURCE_DIR      "${CMAKE_BINARY_DIR}/libmongoc"
#            BINARY_DIR      "${CMAKE_BINARY_DIR}/libmongoc-build"
#            INSTALL_DIR     "${CMAKE_BINARY_DIR}/libmongoc-install"
#            CMAKE_CACHE_ARGS
#            ${common_cmake_cache_args}
#            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/libmongoc-install
#            -DENABLE_TESTS:BOOL=OFF
#            -DENABLE_STATIC:BOOL=OFF
#            -DENABLE_EXAMPLES:BOOL=OFF
#            -DENABLE_EXTRA_ALIGNMENT:BOOL=OFF
#            #INSTALL_COMMAND ""
#            )
#    set(libmongoc-1.0_DIR "${CMAKE_BINARY_DIR}/libmongoc-install/lib/cmake/libmongoc-1.0/")
#    set(libbson-1.0_DIR "${CMAKE_BINARY_DIR}/libmongoc-install/lib/cmake/libbson-1.0/")
#
#    ExternalProject_Add(libmongocxx
#            GIT_REPOSITORY  "https://github.com/mongodb/mongo-cxx-driver.git"
#            GIT_TAG         "r3.3.1"
#            GIT_PROGRESS    1
#            GIT_SHALLOW     1
#            SOURCE_DIR      "${CMAKE_BINARY_DIR}/libmongocxx"
#            BINARY_DIR      "${CMAKE_BINARY_DIR}/libmongocxx-build"
#            INSTALL_DIR     "${CMAKE_BINARY_DIR}/libmongocxx-install"
#            CMAKE_CACHE_ARGS
#            ${common_cmake_cache_args}
#            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/libmongocxx-install
#            -DBUILD_SHARED_LIBS:BOOL=ON
#            -DENABLE_TESTS:BOOL=OFF
#            -DENABLE_EXAMPLES:BOOL=OFF
#            -DBSONCXX_POLY_USE_BOOST:BOOL=OFF
#            -DBSONCXX_POLY_USE_MNMLSTC:BOOL=ON
#            -DBSONCXX_POLY_USE_STD:BOOL=OFF
#            -Dlibmongoc-1.0_DIR:PATH=${libmongoc-1.0_DIR}
#            -Dlibbson-1.0_DIR:PATH=${libbson-1.0_DIR}
#            DEPENDS
#            libmongoc
#            )
#    set(libmongocxx_DIR "${CMAKE_BINARY_DIR}/libmongocxx-install/lib/cmake/libmongocxx-3.3.1/")
#    set(libbsoncxx_DIR "${CMAKE_BINARY_DIR}/libmongocxx-install//lib/cmake/libbsoncxx-3.3.1/")
#
#
#    function(ExternalProject_AlwaysConfigure proj)
#        # This custom external project step forces the configure and later
#        # steps to run.
#        _ep_get_step_stampfile(${proj} "configure" stampfile)
#        ExternalProject_Add_Step(${proj} forceconfigure
#                COMMAND ${CMAKE_COMMAND} -E remove ${stampfile}
#                COMMENT "Forcing configure step for '${proj}'"
#                DEPENDEES build
#                ALWAYS 1
#                )
#    endfunction()
#
#    ExternalProject_Add(${PROJECT_NAME}
#            SOURCE_DIR "${CMAKE_SOURCE_DIR}"
#            BINARY_DIR "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-build"
#            DOWNLOAD_COMMAND ""
#            UPDATE_COMMAND ""
#            CMAKE_CACHE_ARGS
#            ${common_cmake_cache_args}
#            -D${PROJECT_NAME}_SUPERBUILD:BOOL=OFF
#            -Dlibbsoncxx_DIR:PATH=${libbsoncxx_DIR}
#            -Dlibmongocxx_DIR:PATH=${libmongocxx_DIR}
#            INSTALL_COMMAND ""
#            DEPENDS
#            libmongocxx
#            )
#    ExternalProject_AlwaysConfigure(${PROJECT_NAME})
#    return()
#endif()
#message(STATUS "Configuring inner-build")
#find_package(libmongocxx REQUIRED)
#
##set(BOOST_ROOT "boost")
##find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
##message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
#
##include_directories(${Boost_INCLUDE_DIRS})
##include_directories(${Boost_LIBRARIES})
##include_directories(${BOOST_ROOT})
#set(DEBUG_CXX_FLAGS "-std=c++17 -pthread -g3 ")
#set(DEBUG_C_FLAGS "-std=c99 -pthread -g3")
#
##add_subdirectory(src/server/lib/CompanyServer)
#
#    # Set flags
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_CXX_FLAGS}")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_C_FLAGS}")
#
#    add_executable (test_mongocxx
#            main.cpp
#            )
#
#    target_link_libraries(test_mongocxx
##            ServerApp
#            ${LIBMONGOCXX_LIBRARIES}
##            ${LIBBSONCXX_LIBRARIES}
#            )
#
#target_include_directories(test_mongocxx PUBLIC ${LIBMONGOCXX_INCLUDE_DIRS})
#target_compile_definitions(test_mongocxx PUBLIC ${LIBMONGOCXX_DEFINITIONS})


cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 11)

project(Test)

option(${PROJECT_NAME}_SUPERBUILD "Build ${PROJECT_NAME} and the projects it depends on." ON)

if(${PROJECT_NAME}_SUPERBUILD)

    include(ExternalProject)

    set(common_cmake_cache_args
            -DCMAKE_CXX_COMPILER:PATH=${CMAKE_CXX_COMPILER}
            )
    if(NOT DEFINED CMAKE_CONFIGURATION_TYPES)
        list(APPEND common_cmake_cache_args
                -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
                )
    endif()

    ExternalProject_Add(libmongoc
            GIT_REPOSITORY  "https://github.com/mongodb/mongo-c-driver.git"
            GIT_TAG         "1.12.0"
            GIT_PROGRESS    1
            GIT_SHALLOW     1
            SOURCE_DIR      "${CMAKE_BINARY_DIR}/libmongoc"
            BINARY_DIR      "${CMAKE_BINARY_DIR}/libmongoc-build"
            INSTALL_DIR     "${CMAKE_BINARY_DIR}/libmongoc-install"
            CMAKE_CACHE_ARGS
            ${common_cmake_cache_args}
            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/libmongoc-install
            -DENABLE_TESTS:BOOL=OFF
            -DENABLE_STATIC:BOOL=OFF
            -DENABLE_EXAMPLES:BOOL=OFF
            -DENABLE_EXTRA_ALIGNMENT:BOOL=OFF
            #INSTALL_COMMAND ""
            )
    set(libmongoc-1.0_DIR "${CMAKE_BINARY_DIR}/libmongoc-install/lib/cmake/libmongoc-1.0/")
    set(libbson-1.0_DIR "${CMAKE_BINARY_DIR}/libmongoc-install/lib/cmake/libbson-1.0/")

    ExternalProject_Add(libmongocxx
            GIT_REPOSITORY  "https://github.com/mongodb/mongo-cxx-driver.git"
            GIT_TAG         "r3.3.1"
            GIT_PROGRESS    1
            GIT_SHALLOW     1
            SOURCE_DIR      "${CMAKE_BINARY_DIR}/libmongocxx"
            BINARY_DIR      "${CMAKE_BINARY_DIR}/libmongocxx-build"
            INSTALL_DIR     "${CMAKE_BINARY_DIR}/libmongocxx-install"
            CMAKE_CACHE_ARGS
            ${common_cmake_cache_args}
            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/libmongocxx-install
            -DBUILD_SHARED_LIBS:BOOL=ON
            -DENABLE_TESTS:BOOL=OFF
            -DENABLE_EXAMPLES:BOOL=OFF
            -DBSONCXX_POLY_USE_BOOST:BOOL=OFF
            -DBSONCXX_POLY_USE_MNMLSTC:BOOL=ON
            -DBSONCXX_POLY_USE_STD:BOOL=OFF
            -Dlibmongoc-1.0_DIR:PATH=${libmongoc-1.0_DIR}
            -Dlibbson-1.0_DIR:PATH=${libbson-1.0_DIR}
            DEPENDS
            libmongoc
            )
    set(libmongocxx_DIR "${CMAKE_BINARY_DIR}/libmongocxx-install/lib/cmake/libmongocxx-3.3.1/")
    set(libbsoncxx_DIR "${CMAKE_BINARY_DIR}/libmongocxx-install//lib/cmake/libbsoncxx-3.3.1/")


    function(ExternalProject_AlwaysConfigure proj)
        # This custom external project step forces the configure and later
        # steps to run.
        _ep_get_step_stampfile(${proj} "configure" stampfile)
        ExternalProject_Add_Step(${proj} forceconfigure
                COMMAND ${CMAKE_COMMAND} -E remove ${stampfile}
                COMMENT "Forcing configure step for '${proj}'"
                DEPENDEES build
                ALWAYS 1
                )
    endfunction()

    ExternalProject_Add(${PROJECT_NAME}
            SOURCE_DIR "${CMAKE_SOURCE_DIR}"
            BINARY_DIR "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-build"
            DOWNLOAD_COMMAND ""
            UPDATE_COMMAND ""
            CMAKE_CACHE_ARGS
            ${common_cmake_cache_args}
            -D${PROJECT_NAME}_SUPERBUILD:BOOL=OFF
            -Dlibbsoncxx_DIR:PATH=${libbsoncxx_DIR}
            -Dlibmongocxx_DIR:PATH=${libmongocxx_DIR}
            INSTALL_COMMAND ""
            DEPENDS
            libmongocxx
            )
    ExternalProject_AlwaysConfigure(${PROJECT_NAME})
    return()
endif()

message(STATUS "Configuring inner-build")

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)

set(BOOST_ROOT "boost")
find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")

add_subdirectory(src/server/lib/CompanyServer)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Boost_LIBRARIES})
include_directories(${BOOST_ROOT})


set(DEBUG_CXX_FLAGS "-std=c++17 -pthread -lpthread -lboost_thread -g3 ")
set(DEBUG_C_FLAGS "-std=c99 -pthread -g3")


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
if (CMAKE_BUILD_TYPE MATCHES Debug)
    # Set flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_C_FLAGS}")

    add_executable (${PROJECT_NAME}
            main.cpp
            )

    target_link_libraries(${PROJECT_NAME}
            ServerApp
            ${LIBMONGOCXX_LIBRARIES}
            #            ${LIBBSONCXX_LIBRARIES}
            )

elseif (CMAKE_BUILD_TYPE MATCHES Test)

    if (CMAKE_VERSION VERSION_LESS 3.2)
        set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
    else()
        set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
    endif()


    include(config/gtest/DownloadProject.cmake)
    download_project(PROJ                googletest
            GIT_REPOSITORY      https://github.com/google/googletest.git
            GIT_TAG             master
            ${UPDATE_DISCONNECTED_IF_AVAILABLE}
            )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

    if (CMAKE_VERSION VERSION_LESS 2.8.11)
        include_directories("${gtest_SOURCE_DIR}/include"
                "${gmock_SOURCE_DIR}/include")
    endif()

    # Set flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_C_FLAGS} -fprofile-arcs -ftest-coverage")


    add_executable(test_mongocxx
            src/server/lib/CompanyServer/Tests/gmockTests.cpp
            src/server/Tests/test.cpp
            )

    target_link_libraries(test_mongocxx PUBLIC
            gtest
            gmock_main
            # gcov
            ServerApp
            ${LIBMONGOCXX_LIBRARIES}
            ${LIBBSONCXX_LIBRARIES})

    target_include_directories(test_mongocxx PUBLIC
            ${LIBMONGOCXX_INCLUDE_DIRS}
            ${LIBBSONCXX_INCLUDE_DIR}
            ${PROJECT_SOURCE_DIR})

    target_compile_definitions(test_mongocxx PUBLIC ${LIBMONGOCXX_DEFINITIONS})

    add_test(run_tests run_tests)

elseif (CMAKE_BUILD_TYPE MATCHES Release)
    # Set flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${RELEASE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${RELEASE_C_FLAGS}")

    add_executable (${PROJECT_NAME}
            main.cpp
            )

    target_link_libraries(${PROJECT_NAME}
            ServerApp
            )

endif ()


#add_executable(test_mongocxx main.cpp)


#add_subdirectory(src/server/lib/CompanyServer)

# Set flags
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_CXX_FLAGS}")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_C_FLAGS}")

#    target_link_libraries(test_mongocxx
##            ServerApp
#            ${LIBMONGOCXX_LIBRARIES}
##            ${LIBBSONCXX_LIBRARIES}
#            )
#
#
#target_link_libraries(test_mongocxx PUBLIC
#        ServerApp
#        ${LIBMONGOCXX_LIBRARIES}
#        ${LIBBSONCXX_LIBRARIES})
#
#target_include_directories(test_mongocxx PUBLIC
#        ${LIBMONGOCXX_INCLUDE_DIRS}
#        ${LIBBSONCXX_INCLUDE_DIR}
#        ${PROJECT_SOURCE_DIR})
#
#target_compile_definitions(test_mongocxx PUBLIC ${LIBMONGOCXX_DEFINITIONS})
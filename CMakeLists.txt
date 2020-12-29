cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME Application)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)


# ---------- Compiling flags ----------
# Release flags
set(RELEASE_CXX_FLAGS "-std=c++17 -Wall -Werror -pedantic")
set(RELEASE_C_FLAGS "-std=c99 -Wall -Werror -pedantic")
# Debug flags
set(DEBUG_CXX_FLAGS "-std=c++17 -pthread -g3")
set(DEBUG_C_FLAGS "-std=c99 -pthread -g3")


# -------- Build lib ---------
add_subdirectory(src/client)


# ---------- Build target -----------
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
if (CMAKE_BUILD_TYPE MATCHES Debug)
    # Set flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DEBUG_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${DEBUG_C_FLAGS}")

    add_executable (${PROJECT_NAME}
            src/client/main.cpp
            )

    target_link_libraries(${PROJECT_NAME}
            AppClient

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


    add_executable(${PROJECT_NAME}
            src/client/test/gmock.cpp
            src/client/test/gtest.cpp
            src/client/test/test.cpp
            )

    target_link_libraries(${PROJECT_NAME}
            gtest
            gmock_main
            gcov
            AppClient
            )

    add_test(run_tests run_tests)

elseif (CMAKE_BUILD_TYPE MATCHES Release)
    # Set flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${RELEASE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${RELEASE_C_FLAGS}")

    add_executable (${PROJECT_NAME}
            src/client/main.cpp
            )

    target_link_libraries(${PROJECT_NAME}
            AppClient
            )
endif ()

target_include_directories(Application PUBLIC "${PROJECT_SOURCE_DIR}")

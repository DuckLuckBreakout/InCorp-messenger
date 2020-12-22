cmake_minimum_required(VERSION 3.16)
project(AppClient LANGUAGES CXX)

# Add Client lib
add_subdirectory(lib/Client)

# Add QT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


# Views
set(VIEWS_HEADERS
        ui/Views/ChatView/chatview.h
        ui/Views/GroupListView/grouplistview.h
        ui/Views/TextView/textview.h
        ui/Views/Models/ChatModel/chatmodel.h
        ui/Views/Models/GroupModel/groupmodel.h
        ui/Views/Models/LogModel/logmodel.h
        ui/Views/Delegates/ChatDelegate/chatdelegate.h
        ui/Views/Delegates/GroupDelegate/groupdelegate.h
        ui/Views/LogView/logview.h
        )

set(VIEWS_SOURCES
        ui/Views/ChatView/chatview.cpp
        ui/Views/LogView/logview.cpp
        ui/Views/GroupListView/grouplistview.cpp
        ui/Views/TextView/textview.cpp
        ui/Views/Models/ChatModel/chatmodel.cpp
        ui/Views/Models/LogModel/logmodel.cpp
        ui/Views/Models/GroupModel/groupmodel.cpp
        ui/Views/Delegates/ChatDelegate/chatdelegate.cpp
        ui/Views/Delegates/LogDelegate/logdelegate.cpp
        ui/Views/Delegates/GroupDelegate/groupdelegate.cpp
        )

# Delegates
set(DELEGATE_HEADERS
        ui/Viewer/Viewer.h
        ui/Callbacks/Login.h
        ui/Callbacks/Log.h
        ui/Callbacks/Chat.h
        ui/UserData/UserData.h
        )

set(DELEGATE_SOURCES
        ui/Viewer/Viewer.cpp
        )

#Widgets
set(WIDGET_HEADERS
        ui/LoginWidget/loginwidget.h
        ui/LogWidget/logwidget.h
        ui/MenuWidget/menuwidget.h
        ui/MainWidget/mainwidget.h

        )

set(WIDGET_SOURCES
        ui/LoginWidget/loginwidget.cpp
        ui/LogWidget/logwidget.cpp
        ui/MenuWidget/menuwidget.cpp
        ui/MainWidget/mainwidget.cpp

        )

set(FORMS_UI
        ui/MainWidget/mainwidget.ui
        ui/LogWidget/logwidget.ui
        ui/MenuWidget/menuwidget.ui
        ui/LoginWidget/loginwidget.ui
        )

# Create lib AppClient with GUI
add_library(AppClient
        main.cpp
        ${VIEWS_HEADERS} ${VIEWS_SOURCES}
        ${DELEGATE_HEADERS} ${DELEGATE_SOURCES}
        ${WIDGET_HEADERS} ${WIDGET_SOURCES}
        ${FORMS_UI}
        )

target_link_libraries(AppClient Qt5::Widgets Qt5::Core Qt5::Gui Client ${USED_LIBS})
target_include_directories(AppClient PUBLIC "${PROJECT_SOURCE_DIR}")

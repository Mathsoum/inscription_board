cmake_minimum_required(VERSION 3.1)

project(inscription_board LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick Sql Svg REQUIRED)

add_executable(${PROJECT_NAME}
    "main.cpp"
    "maincontroller.cpp"
    "viewModel/mainlistmodel.cpp"
    "model/databasemanager.cpp"
    "model/registration.cpp"
    "qml.qrc"
    )

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Sql Qt5::Svg)

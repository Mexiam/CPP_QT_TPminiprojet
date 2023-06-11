cmake_minimum_required(VERSION 3.10)
project(CPP_QT_TPminiprojet)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

file (GLOB_RECURSE sourceCode src/*.cpp src/*.h)

add_executable(CPP_QT_TPminiprojet ${sourceCode} src/Ennemy.cpp assets.qrc src/ScoreBoard.cpp src/StartScreen.cpp src/ScoreBoard.cpp src/Missile.cpp)

target_link_libraries(CPP_QT_TPminiprojet Qt6::Widgets Qt6::Multimedia)
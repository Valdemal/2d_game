cmake_minimum_required(VERSION 3.17)
project(OOP_RGZ)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES headers/Game/Game.h headers/Game/Game.cpp headers/Player/Player.cpp headers/Player/Player.h headers/Level/Level.cpp headers/Level/Level.h headers/Animation/Animation.cpp headers/Animation/Animation.h)

add_executable(OOP_RGZ main.cpp ${SOURCES})

# Подключение SFML
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(OOP_RGZ sfml-system sfml-window sfml-graphics sfml-audio)

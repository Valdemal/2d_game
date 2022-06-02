cmake_minimum_required(VERSION 3.17)
project(OOP_RGZ)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        headers/Enemy/Clone.hpp
        headers/Animation/Animation.cpp headers/Animation/Animation.h
        headers/Animation/AnimationManager.cpp headers/Animation/AnimationManager.h
        headers/Player/Player.cpp headers/Player/Player.h
        headers/Map/Map.cpp headers/Map/Map.h
        headers/Entity/Entity.cpp headers/Entity/Entity.h
        headers/UI/Message.cpp headers/UI/Message.h headers/UI/UI.hpp
        headers/Level/entityFactory.hpp
        headers/Character/Character.cpp headers/Character/Character.h
        headers/Modifier/Modifier.hpp
        headers/Modifier/HealthBooster.hpp
        headers/Enemy/Enemy.hpp
        headers/Bullet/Bullet.cpp headers/Bullet/Bullet.h headers/Controller/Controller.cpp headers/Controller/Controller.h headers/Level/Level.cpp headers/Level/Level.h)

add_executable(OOP_RGZ main.cpp ${SOURCES})

# Подключение SFML
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(OOP_RGZ sfml-system sfml-window sfml-graphics sfml-audio)

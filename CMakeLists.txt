cmake_minimum_required(VERSION 3.16.3)

project(ASTROIDS)

add_executable(${PROJECT_NAME} src/main.cpp src/Player/Player.cpp src/Game/Game.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC external/sfml/include src/Game/ src/Player/)

target_link_directories(${PROJECT_NAME} PUBLIC external/sfml/lib)

target_link_libraries(${PROJECT_NAME} libsfml-audio.so libsfml-graphics.so sfml-system libsfml-window.so)
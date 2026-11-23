cmake_minimum_required(VERSION 3.16)
project(light_room)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)

add_executable(light_room
    main.cpp
    RaySolver.cpp
    SceneController.cpp
    Renderer.cpp
)

target_link_libraries(light_room sfml-graphics sfml-window)

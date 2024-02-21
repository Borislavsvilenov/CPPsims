cmake_minimum_required(VERSION 3.27)
project(Temple_of_the_Fallen)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

include_directories(objects)

add_executable(Temple_of_the_Fallen
        objects/Circle.cpp
        objects/Circle.hpp
        objects/PhysicsCircle.cpp
        objects/PhysicsCircle.hpp
        objects/PhysicsRect.cpp
        objects/PhysicsRect.hpp
        objects/Rect.cpp
        objects/Rect.hpp
        main.cpp)

target_link_libraries(Temple_of_the_Fallen PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

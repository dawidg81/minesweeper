cmake_minimum_required(VERSION 3.15)

project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_project
    main.cpp
    src/game.cpp
)

target_include_directories(my_project PRIVATE
    src
)

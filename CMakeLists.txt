cmake_minimum_required(VERSION 3.15)

project(minesweeper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(minesweeper
    src/main.cpp
    src/game/game.cpp
)

target_include_directories(minesweeper PRIVATE
    src
)

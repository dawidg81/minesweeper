cmake_minimum_required(VERSION 3.13)
project(minesweeper)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
src/main.cpp
src/Game/edit.cpp
src/Game/display.cpp
src/Game/init.cpp
src/Utils/catch.cpp
)

add_executable(minesweeper ${SOURCE_FILES})

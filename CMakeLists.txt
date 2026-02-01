cmake_minimum_required(VERSION 3.13)

<<<<<<< HEAD
set(SOURCE_FILES
src/main.cpp
src/Game/edit.cpp
src/Game/display.cpp
src/Game/init.cpp
src/Utils/catch.cpp
=======
project(minesweeper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
>>>>>>> e6a7c80d3261e8b0c3e73294c0dace4d36158c5d
)

add_executable(minesweeper)

target_sources(minesweeper PRIVATE ${SOURCE_FILES})

enable_testing()

add_test(
    NAME runs_minesweeper
    COMMAND minesweeper
)
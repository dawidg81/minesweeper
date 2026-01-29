cmake_minimum_required(VERSION 3.13)

project(minesweeper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(minesweeper)

target_sources(minesweeper PRIVATE ${SOURCE_FILES})

enable_testing()

add_test(
    NAME runs_minesweeper
    COMMAND minesweeper
)
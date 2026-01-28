cmake_minimum_required(VERSION 3.13)
project(minesweeper)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
src/*,
src/Game/*,
src/Utils/*,
)

add_executable(minesweeper ${SOURCE_FILES})

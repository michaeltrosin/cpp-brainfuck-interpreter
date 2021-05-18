cmake_minimum_required(VERSION 3.17)
project(brainfuck C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS " -static")

# add_compile_definitions(BUILD_DEBUG)

# add_library(${PROJECT_NAME})
add_executable(${PROJECT_NAME} main.cpp BrainfuckInterpreter.cpp BrainfuckInterpreter.h BrainfuckInterpreter.cpp BrainfuckInterpreter.h)

target_link_libraries(${PROJECT_NAME} -static-libgcc -static-libstdc++)

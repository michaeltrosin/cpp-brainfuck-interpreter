cmake_minimum_required(VERSION 3.17)
project(Utils)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS " -static")

add_library(Utils
        utils/assertion.h
        utils/file.cpp
        utils/file.h
        utils/logging.h
        utils/macros.h
        )

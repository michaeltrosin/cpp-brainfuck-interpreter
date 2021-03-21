cmake_minimum_required(VERSION 3.17)
project(<name>)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS " -static")

# add_compile_definitions(BUILD_DEBUG)

# add_library(<name>)
# add_executable(<name>)

target_link_libraries(<name> -static-libgcc -static-libstdc++)

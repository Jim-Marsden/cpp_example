cmake_minimum_required(VERSION 3.20)
project(cpp_example)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_example main.cpp package_task.cpp package_task.hpp)

target_link_libraries(cpp_example PRIVATE pthread)

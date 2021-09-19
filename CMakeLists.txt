cmake_minimum_required(VERSION 3.20)
project(cpp_example)

set(CMAKE_CXX_STANDARD 20)


add_library(dll_example SHARED
        numbers/dll_add_numbers.h
        numbers/dll_add_numbers.cpp)
add_executable(cpp_example main.cpp numbers/dll_add_numbers.h package_task.cpp package_task.hpp)

target_link_libraries(cpp_example PRIVATE dll_example)

#
##I think the cable is okay!
#cmake_minimum_required(VERSION 3.20)
#project(cpp_example)
#
#set(CMAKE_CXX_STANDARD 17)
#
##add_subdirectory(numbers)
#add_library(dll_example SHARED
#        numbers/dll_add_numbers.cpp numbers/dll_add_numbers.h)
##target_compile_definitions(dll_example PUBLIC dll_example)
#
#add_executable(cpp_example main.cpp package_task.cpp package_task.hpp)
#
#target_link_libraries(cpp_example PRIVATE dll_example)
#
##if(UNIX)
##
##    set(link_libs ${link_libs} pthread dll_example)
##    target_link_libraries(cpp_example PRIVATE ${link_libs})
##
##    #target_link_libraries(cpp_example PRIVATE pthread)
##elseif (WIN32)
###    set(link_libs ${link_libs} dll_example)
##
##    message("win32")
##endif()
#

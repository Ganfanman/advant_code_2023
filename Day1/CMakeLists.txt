cmake_minimum_required(VERSION 3.26)
project(Employee_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(../Utility/data)
include_directories(src)
include_directories(../Utility/include)
include_directories(../Utility/src)

add_executable(main
        ../Utility/include/Utility.h
        ../Utility/src/Utility.cpp
        src/day1.cpp)

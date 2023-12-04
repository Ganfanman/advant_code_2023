cmake_minimum_required(VERSION 3.26)
project(Employee_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(../Utility/data)
include_directories(../Utility/include)
include_directories(../Utility/src)
include_directories(include)
include_directories(src)

add_executable(main
        src/day2.cpp
        include/CubeConundrum.h
        src/CubeConundrum.cpp
        include/GamePower.h
        src/GamePower.cpp
        include/FindColorBall.h
        src/FindColorBall.cpp
)

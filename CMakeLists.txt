cmake_minimum_required(VERSION 3.5 )

### c++11 standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project( team13 )

include_directories(include)

### Generate executables
add_executable( FindMutation apps/findMutation.cpp )





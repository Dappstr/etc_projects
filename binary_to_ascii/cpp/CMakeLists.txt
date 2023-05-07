cmake_minimum_required(VERSION 3.1)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++11-extensions")

file(GLOB SOURCES "src/*.cpp")

add_executable(my_executable ${SOURCES})

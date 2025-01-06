cmake_minimum_required(VERSION 3.20)
project(cppdetect LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 17)

add_executable(cppdetect src/main.cpp)


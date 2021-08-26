# cmake_minimum_required(VERSION <specify CMake version here>)
project(demo1)

set(CMAKE_CXX_STANDARD 98)

add_executable(demo1  test1/T12.cpp test1/T12.h test1/T13.h test1/T4.cpp test1/T4.h)
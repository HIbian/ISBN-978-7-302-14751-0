cmake_minimum_required(VERSION 3.22)
project(c_review C)

set(CMAKE_C_STANDARD 99)

add_executable(c_review "test.c" "MyArrayList.h" "MyArrayList.c")

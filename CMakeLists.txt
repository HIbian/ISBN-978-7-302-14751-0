cmake_minimum_required(VERSION 3.22)
project(c_review C)

set(CMAKE_C_STANDARD 99)

add_executable(2.2 "Chapter2 线性表/2.2线性表的顺序表示实现/test.c" "Chapter2 线性表/2.2线性表的顺序表示实现/MyArrayList.h" "Chapter2 线性表/2.2线性表的顺序表示实现/MyArrayList.c")
add_executable(2.3 "Chapter2 线性表/2.3 线性表链式表实现/test2.3.c" "Chapter2 线性表/2.3 线性表链式表实现/MyLinkList.h" "Chapter2 线性表/2.3 线性表链式表实现/MyLinkList.c")

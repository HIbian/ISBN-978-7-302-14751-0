cmake_minimum_required(VERSION 3.22)
project(c_review C)

set(CMAKE_C_STANDARD 99)

add_executable(2.2 "Chapter2 线性表/2.2线性表的顺序表示实现/test.c" "Chapter2 线性表/2.2线性表的顺序表示实现/MyArrayList.h" "Chapter2 线性表/2.2线性表的顺序表示实现/MyArrayList.c" "Chapter4 串/4.2 串的堆分配存储表示/MyString.h")
add_executable(2.3 "Chapter2 线性表/2.3 线性表链式表实现/test2.3.c" "Chapter2 线性表/2.3 线性表链式表实现/MyLinkList.h" "Chapter2 线性表/2.3 线性表链式表实现/MyLinkList.c")
add_executable(3.1 "Chapter3 栈和队列/3.1-3.2栈/test3.1.c" "Chapter3 栈和队列/3.1-3.2栈/MyStack.h" "Chapter3 栈和队列/3.1-3.2栈/MyStack.c")
add_executable(3.4 "Chapter3 栈和队列/3.4队列/MyQueue.c" "Chapter3 栈和队列/3.4队列/MyQueue.h" "Chapter3 栈和队列/3.4队列/test3.4.c")
add_executable(4.2 "Chapter4 串/4.2 串的堆分配存储表示/MyString.h" "Chapter4 串/4.2 串的堆分配存储表示/MyString.c" "Chapter4 串/4.2 串的堆分配存储表示/test.4.2.c" )
add_executable(6.2 "Chapter6 树和二叉树/6.2 二叉树的链式存储/MyBinaryTree.h" "Chapter6 树和二叉树/6.2 二叉树的链式存储/MyBinaryTree.c" "Chapter6 树和二叉树/6.2 二叉树的链式存储/test6.2.c" "Chapter6 树和二叉树/6.2 二叉树的链式存储/NodeQueue.c")
add_executable(7 "Chapter7 图/BasicTest.c" "Chapter7 图/MyGraph.h" "Chapter7 图/Mygraph.c")


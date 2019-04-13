cmake_minimum_required(VERSION 3.12.1)
project(LinkedListVsBinarySearchTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedListVsBinaryTree main.cpp LinkedList.cpp LinkedList.h BinarySearchTree.h Location.cpp Location.h BinarySearchTree.cpp)
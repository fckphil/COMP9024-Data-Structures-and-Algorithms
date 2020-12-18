cmake_minimum_required(VERSION 3.15)
project(ass8 C)

set(CMAKE_C_STANDARD 99)

add_executable(ass8 main.c BST.h BST.c queue.c queue.h RBTree.h RBTree.c)
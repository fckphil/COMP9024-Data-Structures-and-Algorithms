cmake_minimum_required(VERSION 3.15)
project(9024ass5 C)

set(CMAKE_C_STANDARD 99)

add_executable(9024ass5 main.c WGraph.h PQueue.h PQueue.c WGraph.c dijkstra.c)
cmake_minimum_required(VERSION 3.15)
project(goNSW C)

set(CMAKE_C_STANDARD 99)

add_executable(goNSW main.c queue.c queue.h WGraph.c WGraph.h PQueue.c PQueue.h)
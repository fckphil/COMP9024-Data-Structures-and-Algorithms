cmake_minimum_required(VERSION 3.15)
project(project1 C)

set(CMAKE_C_STANDARD 99)

add_executable(project1 main.c Stack.c Stack.h brackets.c euclid.c gcd.c insertion_sort.c)
cmake_minimum_required(VERSION 3.28)
project(cpp_algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_algorithms main.cpp
        test.cpp
        utils.h
        linear_search.h
        binary_search.h
        ternary_search.h
        quick_sort.h)

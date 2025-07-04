cmake_minimum_required(VERSION 3.31)
project(Solutions)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solutions hashmap/hashmap-test.cpp
        hashmap/hashmap.h
        main.cpp
        leetcode/LeetCodes.cpp
        leetcode/LeetCodes.h
        leetcode/partitions-tring.cpp
        leetcode/[1]-two-sum.cpp
        leetcode/[3304]-kth-character-I.cpp
        leetcode/[3307]-kth-character-II.cpp
)

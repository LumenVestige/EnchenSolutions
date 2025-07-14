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
        leetcode/[50]-my-pow.cpp
        leetcode/[1394]-find-lucky.cpp
        leetcode/[3]-length-of-longest-substring.cpp
        leetcode/[30]-find-substring.cpp
        leetcode/25-7-5/[1]-concat-hex36.cpp
        leetcode/[3146]-count-days.cpp
        binary_tree/binary_tree.h
        binary_tree/binary_tree-test.cpp
        binary_tree/binary_tree-test.h
        leetcode/[3606]-validate-coupons.cpp
        leetcode/[2410]-match-players-and-trainers.cpp
        leetcode/[458]-25-7-13/[Q1]-process-str-I.cpp
        leetcode/[458]-25-7-13/[Q3]-process-str-II.cpp
        wuxi_university/WuXiUniversity.h
        wuxi_university/2024_OJ/[A]-max-gcd.cpp
        wuxi_university/WuXiUniversity.cpp
)

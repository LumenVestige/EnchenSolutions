cmake_minimum_required(VERSION 3.31)
project(Solutions)

set(CMAKE_CXX_STANDARD 20)

add_executable(Solutions algorithm/hashmap/hashmap-test.cpp
        algorithm/hashmap/hashmap.h
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
        algorithm/binary_tree/binary_tree.h
        algorithm/binary_tree/binary_tree-test.cpp
        algorithm/binary_tree/binary_tree-test.h
        leetcode/[3606]-validate-coupons.cpp
        leetcode/[2410]-match-players-and-trainers.cpp
        leetcode/[458]-25-7-13/[Q1]-process-str-I.cpp
        leetcode/[458]-25-7-13/[Q3]-process-str-II.cpp
        wuxi_university/WuXiUniversity.h
        wuxi_university/2024_OJ/[A]-max-gcd.cpp
        wuxi_university/WuXiUniversity.cpp
        leetcode/[2]-add-two-numbers.cpp
        leetcode/[161]-25-7-19/[Q1]-split-array.cpp
        leetcode/[161]-25-7-19/[Q2]-count-islands.cpp
        leetcode/[1470]-shuffle.cpp
        leetcode/[459]-25-7-20/[Q1]-check-divisibility.cpp
        leetcode/[459]-25-7-20/[Q2]-count-trapezoids.cpp
        leetcode/[200]-num-is-lands.cpp
        codeforces/codeforces.h
        codeforces/codeforces.cpp
        codeforces/[4A]-watermelon.cpp
        codeforces/[71A]-way-too-long-words.cpp
        codeforces/[231A]-team.cpp
        codeforces/[282-A]-bit-pp.cpp
        codeforces/[158A]-nextround.cpp
        algorithm/sort/quicksort.h
        leetcode/[1456]-max-vowels.cpp
        leetcode/[1717]-maximum-gain.cpp
)

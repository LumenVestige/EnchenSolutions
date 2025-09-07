//
// Created by sanenchen on 25-7-4.
//
#include "LeetCodes.h"

double LeetCodes::myPow(double x, int n) {
    long long N = n;
    // if (n < 0) {
    //     N = -N;
    //     x = 1 / x;
    // }
    N = abs(N);
    x = (n < 0) ? 1 / x : x;
    if (N == 0)
        return 1;
    // // 判断奇偶数
    double t = myPow(x, N / 2);
    // if (N % 2 == 0) {
    //     // 偶数
    //     return t * t;
    // }
    // // 奇数
    // return t * t * x;

    // 高级一点的玩法，三目操作符
    return (N % 2 == 0) ? t * t : t * t * x;
}

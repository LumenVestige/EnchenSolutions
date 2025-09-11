//
// Created by sanenchen on 25-9-11.
//
#include <bits/stdc++.h>
using namespace std;

// 二分答案 其实就是暴力模拟 只不过是优化过的暴力模拟
long long minimumTime(vector<int>& time, int totalTrips) {
    // check 函数
    auto check = [&](long long mid)-> bool {
        // 模拟执行
        long long sum = 0;
        for (auto& i : time) {
            sum += mid / i;
        }
        return sum >= totalTrips;
    };

    long long left = 0, right = 0;
    for (auto& i : time)
        right = max(right, (long long)i);
    right *= totalTrips;
    while (left + 1 < right) {
        const long long mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    vector<int> time = {1, 2, 3};
    cout << minimumTime(time, 5);
    return 0;
}
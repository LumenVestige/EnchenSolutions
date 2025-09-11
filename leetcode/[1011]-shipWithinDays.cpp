//
// Created by sanenchen on 25-9-11.
//
#include <bits/stdc++.h>
using namespace std;
int shipWithinDays(vector<int>& weights, int days) {
    // check 函数
    auto check = [&](int mid)-> bool{
        // 最高载重 mid
        int day = 1, point = 0;
        while (point != weights.size()) {
            int day_left = mid;
            while (weights[point] <= day_left && point < weights.size()) {
                day_left -= weights[point];
                point++;
            }
            day++;
        }
        return day - 1 <= days;
    };
    int left = 0, right = 0;
    for (auto& i : weights) {
        right += i;
        left = max(left, i);
    }
    while (left + 1 < right) {
        const int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}
int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << shipWithinDays(weights, 5);
    return 0;
}
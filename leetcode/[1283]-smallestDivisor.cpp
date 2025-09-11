//
// Created by sanenchen on 25-9-11.
//
#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &nums, int threshold) {
    auto check = [&](int mid)-> bool {
        int ans = 0;
        for (int num : nums) {
            ans += (mid + num - 1) / mid;
        }
        return ans <= threshold;
    };
    // 二分答案
    int left = 0, right = 0;
    // 扫一遍 找到最大是
    for (auto& i : nums)
        right = max(right, i);
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    vector<int> nums = {1, 2, 5, 9};
    cout << smallestDivisor(nums, 6);
    return 0;
}

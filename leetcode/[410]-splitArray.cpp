//
// Created by sanenchen on 25-9-13.
//
#include <bits/stdc++.h>
using namespace std;

int splitArray(vector<int>& nums, int k) {
    auto check = [&](int mid)->bool {
        int cnt = 1, s = 0;
        for (int num : nums) {
            if (s + num <= mid) s += num;
            else {
                if (cnt == k) return false;
                cnt++;
                s = num;
            }
            // if (cnt > k) return false;
        }
        return true;
    };
    int left = INT_MAX, right = reduce(nums.begin(), nums.end());
    // 求left最大值
    for (auto& i : nums)
        left = max(left, i);
    left -= 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    vector<int> nums = {7,2,5,10,8};
    cout << splitArray(nums, 2);
    return 0;
}
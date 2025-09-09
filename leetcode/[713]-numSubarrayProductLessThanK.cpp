//
// Created by sanenchen on 25-9-9.
//
#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    // 滑动窗口 主要的操作 入、条件判断、出
    int left = 0, tmp = 1, ans = 0;
    if (k == 0 || k == 1) return 0;
    for (int right = 0; right < nums.size(); ++right) {
        // 入
        tmp *= nums[right];
        // 条件判断是否符合窗口条件
        while (tmp >= k) {
            // 左边移出
            if (left < nums.size())
                tmp /= nums[left];
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1};
    cout << numSubarrayProductLessThanK(nums, 1);
    return 0;
}

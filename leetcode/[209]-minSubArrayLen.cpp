//
// Created by sanenchen on 25-8-20.
//
#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    unordered_map<int, int> prefix;
    // 构建前缀和
    for (int i = 0; i < nums.size(); ++i) {
        prefix[i] = nums[i] + prefix[i - 1];
    }
    // 子段和 = nums[r] - nums[l - 1];
    // 滑动窗口 左右指针 条件：大于等于 target
    int l = 0, ans = INT_MAX;
    for (int r = 0; r < nums.size(); ++r) {
        int sum = prefix[r] - prefix[l - 1];
        if (sum >= target) {
            ans = min(ans, r - l + 1);
            while (l != r && sum >= target) {
                l++;
                sum = prefix[r] - prefix[l - 1];
                if (sum >= target) ans = min(ans, r - l + 1);
            }
            // l = 0;
        }
    }
    return (ans == INT_MAX) ? 0 : ans;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    cout << minSubArrayLen(15, nums);
    return 0;
}

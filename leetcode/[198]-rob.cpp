//
// Created by sanenchen on 25-7-31.
//
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums) {
    vector<int> dp = vector<int>(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); ++i) {
        // 不偷的话 继承上一次
        int not_rob = dp[i - 1];
        // 偷得话 就在dp中找那个偷得数量最大的那个
        int rob = nums[i - 1];
        for (int j = 0; j < i - 1; j++) {
            rob = max(rob, dp[j] + nums[i - 1]);
        }
        dp[i] = max(not_rob, rob);
    }
    for (auto &i: dp) {
        cout << i << " ";
    }
    return dp[nums.size()];
}


int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums);
    return 0;
}

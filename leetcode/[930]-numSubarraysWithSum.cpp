//
// Created by sanenchen on 25-9-10.
//
#include <bits/stdc++.h>

using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal) {
    auto solve = [&](int k) -> int {
        // 多少个元素和大于等于k
        int left = 0, ans = 0, tmp = 0;
        for (int right = 0; right < nums.size(); ++right) {
            tmp += nums[right];
            // 滑到不合法位置
            while (tmp >= k && left < right) {
                tmp -= nums[left];
                left++;
            }
            ans += left;
        }
        return ans;
    };
    return solve(goal) - solve(goal + 1);
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    cout << numSubarraysWithSum(nums, 2);
    return 0;
}

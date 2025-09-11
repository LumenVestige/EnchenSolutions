//
// Created by sanenchen on 25-9-9.
//
#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int> &nums, int k) {
    int maxNum = 0;
    // 预先找到最大值
    for (auto &i: nums) {
        maxNum = max(maxNum, i);
    }
    int cnt = 0, left = 0, ans = 0;
    for (int right = 0; right < nums.size(); ++right) {
        cnt += (nums[right] == maxNum) ? 1 : 0;
        while (cnt >= k) {
            cnt -= (nums[left] == maxNum) ? 1 : 0;
            left++;
        }
        ans += left;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,3,2,3,3};
    cout << countSubarrays(nums, 2);
    return 0;
}

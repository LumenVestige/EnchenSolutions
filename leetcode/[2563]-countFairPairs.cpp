//
// Created by sanenchen on 25-8-16.
//
#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int>& nums, int target, int left) {
    left += -1;
    int right = nums.size();
    while (left + 1 != right) {
        int mid = (left + right) >> 1;
        if (nums[mid] >= target)
            right = mid;
        else left = mid;
    }
    return right;
}

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        // 截取后面的
        // vector<int> sub(nums.begin() + i + 1, nums.end());
        // 排序
        // sort(sub.begin(), sub.end());
        int lowerTarget = lower - nums[i];
        int upperTarget = upper - nums[i];
        int left = lowerBound(nums, lowerTarget, i + 1);
        int right = lowerBound(nums, upperTarget + 1, i + 1);
        ans += right - left;
    }
    return ans;
}
int main() {
    vector<int> nums = {1,7,9,2,5};
    cout << countFairPairs(nums, 11, 11);
    return 0;
}
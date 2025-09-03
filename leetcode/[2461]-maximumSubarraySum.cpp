//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k) {
    long long ans = INT_MIN, prefix = 0, already = 0;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < nums.size(); ++i) {
        prefix += nums[i];
        if (hash_map[nums[i]] != 0) already++;
        hash_map[nums[i]]++;
        if (i + 1 < k) continue;
        if (already == 0) ans = max(ans, prefix);
        // 出
        prefix -= nums[i - k + 1];
        if (hash_map[nums[i - k + 1]] > 1) already--;
        hash_map[nums[i - k + 1]]--;
    }
    return ans == INT_MIN ? 0 : ans;
}

int main() {
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    cout << maximumSubarraySum(nums, 3);
    return 0;
}

//
// Created by sanenchen on 25-7-24.
//
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> g_map;
int findLongestSubHard(vector<int> &nums, int i) {
    // 记忆化搜索 避免重复计算
    if (g_map.find(i) != g_map.end())
        return g_map[i];
    if (i == nums.size() - 1)
        return 1;
    int max_len = 1;
    for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] > nums[i]) {
            max_len = max(max_len, findLongestSubHard(nums, j) + 1);
        }
    }
    // 保存结果
    g_map[i] = max_len;
    return max_len;
}


int main() {
    vector<int> nums = {1, 5, 2, 4, 3};
    int ans = 1;
    for (int i = 0; i < nums.size(); i++) {
        ans = max(ans, findLongestSubHard(nums, i));
    }
    cout << ans;
    return 0;
}

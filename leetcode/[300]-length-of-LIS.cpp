//
// Created by sanenchen on 25-7-24.
//
#include "LeetCodes.h"

int LeetCodes::lengthOfLIS(vector<int> &nums) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[i] = 1;
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i])
                map[i] = max(map[i], map[j] + 1);
        }
    }
    int ans = 0;
    for (auto it : map) {
        ans = max(it.second, ans);
    }
    return ans;
}

//
// Created by sanenchen on 25-7-20.
//
#include "LeetCodes.h"
vector<int> LeetCodes::shuffle(vector<int>& nums, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i ++) {
        ans.push_back(nums[i]);
        ans.push_back(nums[2 + i]);
    }
    return ans;
}
//
// Created by sanenchen on 25-8-4.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> runningSum(vector<int>& nums) {
    // vector<int> prefix(nums);
    // for (int i = 1; i < nums.size(); ++i) {
    //     prefix[i] = prefix[i - 1] + nums[i];
    // }
    // return prefix;
    for (int i = 1; i < nums.size(); ++i) {
        nums[i] = nums[i - 1] + nums[i];
    }
    return nums;
}
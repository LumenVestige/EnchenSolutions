//
// Created by sanenchen on 25-8-4.
//
#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0)
                prefix[0] = nums[0];
            else prefix[i] = prefix[i - 1 ] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};
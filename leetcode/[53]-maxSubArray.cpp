//
// Created by sanenchen on 25-9-1.
//
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums) {
    int num_max = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        nums[i] = max(nums[i - 1] + nums[i], nums[i]);
        num_max = max(num_max, nums[i]);
    }
    return num_max;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    return 0;
}

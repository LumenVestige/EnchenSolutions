//
// Created by sanenchen on 25-8-4.
//
#include <bits/stdc++.h>
using namespace std;

int findMiddleIndex(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        nums[i] = nums[i - 1] + nums[i];
    }
    for (int i = 0; i < nums.size(); ++i) {
        int left = (i == 0) ? 0 : nums[i - 1];
        int right = nums[nums.size() - 1] - nums[i];
        if (left == right)
            return i;
    }
    return -1;
}

int main() {
    vector nums = {1, 1, 1, 1};
    cout << findMiddleIndex(nums);
    return 0;
}

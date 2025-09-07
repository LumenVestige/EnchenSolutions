//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = -1, right = nums.size();
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid;
        else left = mid;
    }
    return right;
}

int maximumCount(vector<int>& nums) {
    int positiveNumber = nums.size() - search(nums, 1);
    int zeroCount = nums.size() - search(nums, 0) - positiveNumber;
    int negativeNumber = nums.size() - zeroCount - positiveNumber;

    return max(positiveNumber, negativeNumber);
}

int main() {
    vector<int> nums = {-3,-2,-1,0,0,1,2};
    cout << maximumCount(nums);
    return 0;
}
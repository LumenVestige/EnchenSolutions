//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = -1, right = nums.size();
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    vector<int> nums = {1,3,5,6};
    cout << searchInsert(nums, 5);
    return 0;
}
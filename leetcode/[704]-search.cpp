//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = -1, right = nums.size();
    // 开区间写法
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= target)
            right = mid;
        else left = mid;
    }
    if (right < nums.size() && nums[right] == target) return right;
    return -1;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    cout << search(nums, 2);
    return 0;
}
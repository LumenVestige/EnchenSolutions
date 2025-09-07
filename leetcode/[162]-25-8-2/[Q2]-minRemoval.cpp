//
// Created by sanenchen on 25-8-2.
//
#include <bits/stdc++.h>
using namespace std;

int minRemoval(vector<int> &nums, int k) {
    // vector<int> dp = vector<int>(nums.size() + 1, 0);
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    // for (int i = 0; i < nums.size(); ++i) {
    //     for (int j = i; j < nums.size(); ++j) {
    //         vector<int> tmp(nums.begin() + i, nums.begin() + j + 1);
    //         if (check(tmp))
    //             ans = min(ans, int(nums.size() - tmp.size()));
    //     }
    // }
    int l = 0;
    for (int r = 0; r < nums.size(); ++r) {
        while (nums[r] > (long long)nums[l] * k) {
            l++;
        }
        ans = min(ans, (int)nums.size() - (r - l + 1));
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 34, 23};
    cout << minRemoval(nums, 2);
    return 0;
}

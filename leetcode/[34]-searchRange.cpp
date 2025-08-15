//
// Created by sanenchen on 25-8-14.
//
#include <bits/stdc++.h>
using namespace std;

int low_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l != r) {
        int mid = (l + r) / 2;
        if (nums[mid] < target)
            l = mid + 1;
        else r = mid;
    }
    return l;
}

vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 0)
        return {-1, -1};
    int l, r;
    l = low_bound(nums, target);
    if (nums[l] != target)
        return {-1, -1};
    r = low_bound(nums, target + 1);
    if (nums[r] == target)
        return {l, r};
    return {l, r};
}



int main() {
    vector<int> nums = {1};
    for (auto &i: searchRange(nums, 1))
        cout << i << " ";
    return 0;
}

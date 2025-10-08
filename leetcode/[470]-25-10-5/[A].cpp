//
// Created by sanenchen on 25-10-5.
//
#include <bits/stdc++.h>
using namespace std;
int alternatingSum(vector<int>& nums) {
    int sA = 0, sB = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i % 2 == 0) sA += nums[i];
        else sB += nums[i];
    }
    return sA - sB;
}
int main() {
    vector<int> nums = {1, 3, 5, 7};
    cout << alternatingSum(nums);
    return 0;
}
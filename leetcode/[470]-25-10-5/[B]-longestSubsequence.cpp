//
// Created by sanenchen on 25-10-5.
//
#include <bits/stdc++.h>
using namespace std;
// 脑筋急转弯。。。
int longestSubsequence(vector<int> &nums) {
    int t = 0, zeroCount = 0;
    for (int num : nums) {
        t ^= num;
        zeroCount += (num == 0) ? 1 : 0;
    }
    if (t != 0)
        return nums.size();
    if (zeroCount == nums.size())
        return 0;
    return nums.size() - 1;
}
int main() {
    vector<int> nums = {1, 2, 3};
    cout << longestSubsequence(nums);
    return 0;
}
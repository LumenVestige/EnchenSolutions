//
// Created by sanenchen on 25-10-10.
//
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
        if (nums[left] != nums[right])
            nums[++left] = nums[right];
    }
    return left + 1;
}
int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums);
    return 0;
}
//
// Created by sanenchen on 25-10-10.
//
#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] != val)
            nums[slow++] = nums[fast];
        fast++;
    }
    return slow;
}
int main() {
    vector<int> nums = {3, 2, 2, 3};
    cout << removeElement(nums, 3);
    return 0;
}
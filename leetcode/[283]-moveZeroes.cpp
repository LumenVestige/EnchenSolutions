//
// Created by sanenchen on 25-8-22.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeroes(vector<int> &nums) {
    int x = 0, countZero = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[x] = nums[i];
            x++;
        } else {
            countZero++;
        }
    }
    while (countZero--) {
        nums[nums.size() - countZero - 1] = 0;
    }
    return nums;
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    for (auto& i : moveZeroes(nums))
        cout << i << " ";
    return 0;
}

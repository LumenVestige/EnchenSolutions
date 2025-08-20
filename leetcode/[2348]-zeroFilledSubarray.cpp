//
// Created by sanenchen on 25-8-19.
//

// 滑动窗口

#include <bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int> &nums) {
    // 双指针 右指针一直向右游走 直到不符合条件 左指针向左走 直到左指针等于右指针
    int j = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            ans += i - j + 1;
        } else {
            while (j - 1 != i) {
                j++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
    cout << zeroFilledSubarray(nums);
    return 0;
}

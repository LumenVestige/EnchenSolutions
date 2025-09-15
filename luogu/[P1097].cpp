//
// Created by sanenchen on 25-9-15.
//
// P1097 [NOIP 2007 提高组] 统计数字
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    // 排个序
    sort(nums.begin(), nums.end());
    // 双指针 一根指的是初始的数字 一根是已经是不等于当前数的指向坐标
    int l = 0, tmp = nums[0];
    for (int r = 0; r <= nums.size(); ++r) {
        if (nums[r] != tmp) {
            cout << tmp << " " << r - l << endl;
            l = r;
            tmp = nums[r];
        }
    }
    return 0;
}
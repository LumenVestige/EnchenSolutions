//
// Created by sanenchen on 25-8-18.
//
#include <bits/stdc++.h>
using namespace std;

bool checkArray(vector<int> &nums, int k) {
    // 使用sum_d 解决了边更新边查询问题 实时的更新diff前缀和
    // // 构建差分数组
    // vector<int> diff(nums.size() + 1);
    // diff[0] = nums[0];
    // for (int i = 1; i < nums.size(); ++i) {
    //     diff[i] = nums[i - 1] + nums[i];
    // }
    // // 遍历nums
    // for (int i = 0; i < nums.size(); ++i) {
    //     if (nums[i] < 0 || i + k > nums.size())
    //         return false;
    //     if (nums[i] == 0)
    //         continue;
    //     if (nums[i] != 0) {
    //         diff[i] -= nums[i];
    //         diff[i + k + 1] += nums[i];
    //         // 更新
    //         for (int j = 1; i < nums.size(); ++j) {
    //             nums[i] = diff[i] + nums[i - 1];
    //         }
    //         for (int k = 1; k < nums.size(); ++k) {
    //             diff[k] = nums[k - 1] + nums[k];
    //         }
    //     }
    //
    // }
    // return true;
    // 使用sum_d 解决了边更新边查询问题 实时的更新diff前缀和
    int sum_d = 0;
    vector<int> diff(nums.size() + 1);
    for (int i = 0; i < nums.size(); ++i) {
        sum_d += diff[i]; // 获取当前差分数组
        // 1. 还原数组
        int x = nums[i];
        x += sum_d; // 还原
        if (x == 0) continue;
        if (x < 0 || i + k > nums.size()) return false;
        sum_d -= x;
        diff[i + k] += x;
    }

    return true;
}

int main() {
    vector<int> nums = {2, 2, 3, 1, 1, 0};
    cout << checkArray(nums, 3);
    return 0;
}

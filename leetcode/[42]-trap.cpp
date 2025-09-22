//
// Created by sanenchen on 25-9-22.
//
#include <bits/stdc++.h>
using namespace std;
int trap1(vector<int> &height) {
    // 接雨水 相向双指针做法
    int left = 0, right = height.size() - 1, ans = 0;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (height[left] < height[right]) {
            ans += leftMax - height[left];
            ++left;
        } else {
            ans += rightMax - height[right];
            --right;
        }
    }
    return ans;
}
int trap(vector<int> &height) {
    // 接雨水 前后缀 分解
    // 从前往后扫描 扫出当前数的前面的最大值
    vector<int> leftMax(height);
    for (int i = 1; i < height.size(); ++i)
        leftMax[i] = max(leftMax[i - 1], height[i]);
    // 从后往前扫，扫出当前数后面的最大值
    vector<int> rightMax(height);
    for (int i = height.size() - 2; i >= 0; --i)
        rightMax[i] = max(rightMax[i + 1], height[i]);
    // 遍历每一个数
    int ans = 0;
    for (int i = 0; i < height.size(); ++i) {
        ans += min(leftMax[i], rightMax[i]) - height[i];
    }
    return ans;
}

int main() {
    vector<int> height = {1,0,3,0,1,1};
    cout << trap(height);
    return 0;
}
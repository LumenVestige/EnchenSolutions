//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>

using namespace std;
int count(int diff, int l, int r) { return diff * min(l, r); }

int maxArea(const vector<int> &height) {
    // 左右开弓 指针在左 右 各有一根 移动小的那一根
    int l = 0, r = height.size() - 1;
    int max_ans = 0;
    while (l != r) {
        max_ans = max(count(r - l, height[l], height[r]), max_ans);
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return max_ans;
}

int main() {
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(nums);
    return 0;
}

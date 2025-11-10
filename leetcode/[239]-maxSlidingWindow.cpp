//
// Created by sanenchen on 25-11-8.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.size() == 1)
        return nums;
    // 构建一个st表
    int n = nums.size();
    int m = log2(n);
    vector<vector<int>> st(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        st[i][0] = nums[i];
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto getMax = [&](int l, int r) {
        int c = log2(r - l + 1);
        return max(st[l][c], st[r - (1 << c) + 1][c]);
    };
    vector<int> ans;
    int left = 0, right = 0;
    while (right < n) {
        if (right - left + 1 < k) {
            right++;
            continue;
        }
        ans.push_back(getMax(left, right));
        left++;
        right++;
    }
    return ans;
}
int main() {
    vector<int> nums = {9, 11};
    for (auto& i : maxSlidingWindow(nums, 2)) {
        cout << i << " ";
    }
    return 0;
}
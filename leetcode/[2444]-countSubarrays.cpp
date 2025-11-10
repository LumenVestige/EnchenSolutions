//
// Created by sanenchen on 25-11-9.
//
#include <bits/stdc++.h>
using namespace std;
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n = nums.size();
    int k = log2(n);
    vector<vector<int>> stMax(n, vector<int>(k + 1)), stMin(n, vector<int>(k + 1));
    for (int i = 0; i < n; ++i) {
        stMax[i][0] = nums[i];
        stMin[i][0] = nums[i];
    }
    // 构建st
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto getMin = [&](int l, int r) {
        int m = log2(r - l + 1);
        return min(stMin[l][m], stMin[r - (1 << m) + 1][m]);
    };
    auto getMax = [&](int l, int r) {
        int m = log2(r - l + 1);
        return max(stMax[l][m], stMax[r - (1 << m) + 1][m]);
    };
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (getMax(i, j) == maxK && getMin(i, j) == minK)
                ans++;
        }
    }
    // // 滑动窗口
    // int left = 0, right = 0;
    //
    // while (right < n) {
    //     if (right - left + 1 < k) {
    //         right++;
    //         continue;
    //     }
    //     cout << getMax(left, right) << endl;
    //     // 判断
    //     if (getMax(left, right) == maxK && getMin(left, right) == minK)
    //         ans++;
    //     left++;
    //     right++;
    // }
    return ans;
}

int main() {
    vector<int> nums = {1,3,5,2,7,5};
    cout << countSubarrays(nums, 1, 5);
    return 0;
}
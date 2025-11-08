#include <bits/stdc++.h>
using namespace std;

int partitionDisjoint(vector<int>& nums) {
    // 构建一个st表 存着最大值
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
            // 从i开始 向后推 2 ^ (j - 1)
            stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto getMax = [&](int l, int r) {
        int m = log2(r - l + 1);
        return max(stMax[l][m], stMax[r - (1 << m) + 1][m]);
    };
    auto getMin = [&](int l, int r) {
        int m = log2(r - l + 1);
        return min(stMin[l][m], stMin[r - (1 << m) + 1][m]);
    };
    for (int i = 1; i < n; ++i) {
        int mi = getMin(i, n - 1);
        int ma = getMax(0, i - 1);
        if (ma <= mi) {
            return i;
        }
    }
    return 0;
}

int main() {
    vector<int> nums = {5,0,3,8,6};
    cout << partitionDisjoint(nums);
    return 0;
}
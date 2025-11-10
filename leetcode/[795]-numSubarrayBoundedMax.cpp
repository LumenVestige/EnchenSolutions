#include <bits/stdc++.h>
using namespace std;

int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int n = nums.size();
    int k = log2(n);
    vector<vector<int>> st(n, vector<int>(k + 1));
    for (int i = 0; i < n; ++i) {
        st[i][0] = nums[i];
    }
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto getMax = [&](int l, int r) {
        int m = log2(r - l + 1);
        return max(st[l][m], st[r - (1 << m) + 1][m]);
    };
    int l = 0, r = 0, tmp = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int mx = getMax(i, j);
            if (mx >= left && mx <= right) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2,9,2,5,6};
    cout << numSubarrayBoundedMax(nums, 2, 8);
    return 0;
}
//
// Created by sanenchen on 25-8-10.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    // 特判断
    if (k + 1 == n || k > n) {
        cout << -1;
        return 0;
    }
    // 前k个 保证是不动点
    // 后n - k个 保证不是不动点
    vector<int> o_nums(n);
    vector<int> ans(k);
    for (int i = 1; i <= n; ++i) {
        o_nums[i - 1] = i;
    }
    // 前k个 保证一样
    for (int i = 0; i < k; ++i) {
        ans[i] = o_nums[i];
    }
    reverse(o_nums.begin(), o_nums.end());
    o_nums.assign(o_nums.begin(), o_nums.begin() + n - k);
    while (!o_nums.empty()) {
        int next = ans.size() + 1;
        for (int i = 0; i < o_nums.size(); ++i) {
            if (o_nums[i] != next) {
                ans.push_back(o_nums[i]);
                o_nums.erase(o_nums.begin() + i);
                break;
            }
        }
    }
    for (auto& i : ans) {
        cout << i << " ";
    }
    return 0;
}
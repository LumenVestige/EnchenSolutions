//
// Created by sanenchen on 25-8-17.
//
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p, q;
    cin >> n >> p >> q;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<ll> diff(n);
    // 构建差分数组
    for (int i = 0; i < n; ++i) {
        if (i - 1 < 0)
            diff[i] = nums[0];
        else diff[i] = nums[i] - nums[i - 1];
    }
    while (p--) {
        int l, r, x;
        cin >> l >> r >> x;
        diff[l - 1] += x;
        if (r < diff.size())
            diff[r] -= x;
    }
    // 差分数组还原
    nums[0] = diff[0];
    for (int i = 1; i < n; ++i) {
        nums[i] = nums[i - 1] + diff[i];
    }
    // 前缀和数组
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
    return 0;
}

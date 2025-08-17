//
// Created by sanenchen on 25-8-17.
//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        // 前缀和预处理
        for (int i = 1; i < n; ++i) {
            nums[i] = nums[i - 1] + nums[i];
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l == 1)
                cout << nums[r - 1] << endl;
            else cout << nums[r - 1] - nums[l - 2] << endl;
        }
    }
    return 0;
}

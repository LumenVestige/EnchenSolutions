//
// Created by sanenchen on 25-8-2.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    int ans = 0;
    unordered_map<int, int> g_map;
    for (int j = 1; j <= n; ++j) {
        int target = j - nums[j];
        ans += g_map[target];
        g_map[j + nums[j]]++;
    }
    cout << ans;
    return 0;
}
//
// Created by sanenchen on 25-11-9.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    n--;
    unordered_map<int, int> cnt;
    while (n--) {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
    }
    int ans = 0;
    for (auto& [k, v] : cnt) {
        if (v - 2 >= 0) {
            ans += v - 2;
        }
    }
    cout << ans;
    return 0;
}
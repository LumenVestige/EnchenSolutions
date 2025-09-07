//
// Created by sanenchen on 25-8-10.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    vector<int> nums(4);
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        int t;
        cin >> t;
        if (t == i + 1)
            ans++;
    }
    cout << ans;
    return 0;
}
//
// Created by sanenchen on 25-11-9.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int m, n;
    cin >> m >> n;
    int ans = m * (n - 1) + n * (m - 1);
    cout << ans;
    return 0;
}
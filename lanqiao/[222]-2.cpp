//
// Created by sanenchen on 25-11-11.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(int tar) {
    //int tar;
    //cin >> tar;
    int n5 = tar / 5;
    int ans = INT_MAX;
    for (int i = 0; i <= n5; ++i) {
        int tmp = tar - i * 5;
        if (tmp % 3 == 0) {
            ans = min(ans, i + tmp / 3);
        }
    }
    cout <<( (ans == INT_MAX) ? -1 : ans) << endl;
}

void solve2() {
    int t;
    cin >> t;
    int tab[12] = {0, -1, -1, 1, -1, 1, 2, -1, 2, 3, 2, 3};
    if (t < 12) {
        cout << tab[t] << endl;
        return;
    }
    t -= 12;
    int base = 3;
    int a = t / 5;
    int b = t % 5;
    if (b & 1) {
        cout << base + a << endl;
    } else cout << base + a + 1 << endl;
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve2();
    }
    // for (int i = 1; i < 1000; ++i) {
    //     cout << i << ": ";
    //     //solve(i);
    //     solve2(i);
    // }

    return 0;
}
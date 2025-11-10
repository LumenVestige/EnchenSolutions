//
// Created by sanenchen on 25-8-1.
//
#include <bits/stdc++.h>
using namespace std;


signed main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n != 0) {
        if (n >= 100) {
            n -= 100;
            ans++;
            continue;
        }
        if (n >= 20) {
            n -= 20;
            ans++;
            continue;
        }
        if (n >= 10) {
            n -= 10;
            ans++;
            continue;
        }
        if (n >= 5) {
            n -= 5;
            ans++;
            continue;
        }
        n -= 1;
        ans++;
    }
    cout << ans;
    return 0;
}

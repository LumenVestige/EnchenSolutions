//
// Created by sanenchen on 25-8-4.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        while (n != 0) {
            if (n <= k) {
                // 小于后可以直接减去
                n = 0;
                ans++;
                continue;
            }
            // 尽量减去k 如果不行那就 k - 1
            if (((n & 1) == 1 && (k & 1) == 1) || ((n & 1) == 0 && (k & 1) == 0)) {
                n -= k;
            } else
                n -= (k - 1);
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}
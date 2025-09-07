//
// Created by sanenchen on 25-7-31.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    while (m--) {
        int n, w;
        cin >> n >> w;
        vector<int> val(n), wg(n);
        for (int i = 0; i < n; ++i) {
            cin >> val[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> wg[i];
        }
        auto dp = vector(n + 1, vector(w + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= w; ++j) {
                if (wg[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wg[i - 1]] + val[i - 1]);
                }
            }
        }
        cout << dp[n][w] << endl;
    }
    return 0;
}

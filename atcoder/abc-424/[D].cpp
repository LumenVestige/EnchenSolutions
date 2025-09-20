//
// Created by sanenchen on 25-9-20.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> m(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < w; j++)
            m[i][j] = tmp[j] == '#' ? 1 : 0;
    }
    int ans = 0;
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            // 判断他的 四周 是否都是黑
            if (m[i][j] + m[i - 1][j - 1] + m[i - 1][j] + m[i][j - 1] == 4) {
                ans++;
                m[i][j] = 0;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
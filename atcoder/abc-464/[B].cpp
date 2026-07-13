#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; ++i) {
        cin >> g[i];
    }
    int x = 0, y = 0, ht = h, wt = w;
    for (int i = x; i < ht; ++i) {
        int f = 0;
        for (int j = y; j < wt; ++j) {
            if (g[i][j] != '.') f++;
        }
        if (f) break;
        x++;;
    }
    for (int j = y; j < wt; ++j) {
        int f = 0;
        for (int i = x; i < ht; ++i) {
            if (g[i][j] != '.') f++;
        }
        if (f) break;
        y++;
    }
    for (int i = ht-1; i >= x; --i) {
        int f = 0;
        for (int j = y; j < wt; ++j) {
            if (g[i][j] != '.') f++;
        }
        if (f) break;
        ht--;
    }
    for (int j = wt-1; j >= y; --j) {
        int f = 0;
        for (int i = x; i < ht; ++i) {
            if (g[i][j] != '.') f++;
        }
        if (f) break;
        wt--;
    }
    for (int i = x; i < ht; ++i) {
        for (int j = y; j < wt; ++j) {
            cout << g[i][j];
        }
        cout << endl;
    }

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
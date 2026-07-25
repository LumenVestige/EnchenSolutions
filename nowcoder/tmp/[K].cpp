#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i][0] >> p[i][1];
    }
    for (int i = 1; i < n - 1; ++i) {
        int dx1 = p[i][0] - p[i - 1][0];
        int dy1 = p[i][1] - p[i - 1][1];
        int dx2 = p[i + 1][0] - p[i][0];
        int dy2 = p[i + 1][1] - p[i][1];
        int cross = dx1 * dy2 - dy1 * dx2;
        
        if (cross > 0) {
            cout << "LEFT";
        } else if (cross < 0) {
            cout << "RIGHT";
        } else {
            cout << "STRAIGHT";
        }
        cout << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
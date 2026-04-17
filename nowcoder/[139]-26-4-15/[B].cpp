#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {cout << -1; return 0;}
    if (n == 1) {
        cout << 1;
        for (int i = 1; i < m; ++i) {
            cout << 0;
        }
        return 0;
    }
    if (m == 1) {
        cout << 1 << endl;
        for (int i = 1; i < n; ++i) {
            cout << 0 << endl;
        }
        return 0;
    }
    cout << -1;

    return 0;
}
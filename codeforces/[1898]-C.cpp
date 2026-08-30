#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int base = n + m - 2;
    if (k < base || (k - base) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    vector<vector<char>> h(n, vector<char>(m - 1, 'R'));
    vector<vector<char>> v(n - 1, vector<char>(m, 'R'));
    int curCor = 0;
    auto get_char = [](int c) { return c == 0 ? 'R' : 'B'; };
    
    for (int j = 0; j < m - 1; ++j) {
        h[0][j] = get_char(curCor);
        curCor ^= 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        v[i][m - 1] = get_char(curCor);
        curCor ^= 1;
    }
    
    v[0][0] = 'R';
    h[1][0] = 'B';
    v[0][1] = 'R';
    
    char cLast = v[n-2][m-1];
    char cOther = (cLast == 'R' ? 'B' : 'R');
    h[n - 2][m - 2] = cOther;
    v[n - 2][m - 2] = cLast;
    h[n - 1][m - 2] = cOther;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cout << h[i][j] << (j == m - 2 ? "" : " ");
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << v[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
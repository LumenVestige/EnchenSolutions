#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ber(n), ver(m);
    for (int i = 0; i < n; ++i) {
        cin >> ber[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> ver[i];
    }
    int a1 = ber[n-1], a2 = ver[m-1];
    for (int i = 0; i < n-1; ++i) {
        a1 += ber[i]-ber[i+1]+1;
    }
    for (int i = 0; i < m-1; ++i) {
        a2 += ver[i]-ver[i+1]+1;
    }
    // cout << "yy" << a1 << " " << a2 << endl;
    if (a1 >= a2) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
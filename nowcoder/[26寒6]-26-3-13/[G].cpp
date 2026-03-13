#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l;
    cin >> n >> m >>l;
    vector<int> n1(n), n2(m);
    for (int i = 0; i < n; ++i) {
        cin >> n1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> n2[i];
    }
    int d = 0, pos = 0, index = 0;
    for (int i = 0; i < m; ++i) {
        while (d <= pos && index < n) {
            d += n1[index];
            index++;
        }
        if (pos < d && pos + l > d) {
            cout << "YES";
            return 0;
        } else {
            pos += n2[i];
        }
    }
    if (pos < d && pos + l > d) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    vector<int> pathX, pathY;
    while (true) {
        pathX.push_back(x);
        x /= k;
        if (pathX.back() == 0) break;
    }
    while (true) {
        pathY.push_back(y);
        y /= k;
        if (pathY.back() == 0) break;
    }
    int i = pathX.size() - 1;
    int j = pathY.size() - 1;
    while (i >= 0 && j >= 0) {
        if (pathX[i] != pathY[j]) break;
        i--, j--;
    }
    cout << i+j+2 << endl;
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
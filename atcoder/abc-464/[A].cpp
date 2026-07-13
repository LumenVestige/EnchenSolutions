#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    string str;
    cin >> str;
    int a = 0;
    for (auto& i : str) {
        if (i == 'E') {
            a++;
        }
    }
    int b = str.size() - a;
    if (a > b) {
        cout << "East";
    } else {
        cout << "West";
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
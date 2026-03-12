#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    string s1, s2;
    int n; cin >> n;
    cin >> s1 >> s2;
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            if ((s1[i] == 'O' && s2[i] == '0') || (s1[i] == '0' && s2[i] == 'O')) {
                continue;
            }
            if ((s1[i] == '1' && s2[i] == 'l') || (s1[i] == 'l' && s2[i] == 'I') || (s1[i] == '1' && s2[i] == 'I') || (s1[i] == 'I' && s2[i] == '1') || (s1[i] == 'l' && s2[i] == '1') || (s1[i] == 'I' && s2[i] == 'l')) {
                continue;
            }
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
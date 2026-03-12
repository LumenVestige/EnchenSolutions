#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<string, int> cnt;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cnt[s] = 0;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (!cnt.count(s)) {
            cout << "WRONG" << endl;
            continue;
        }
        if (cnt[s] != 0) {
            cout << "REPEAT" << endl;
            continue;
        }
        cout << "OK" << endl;
        cnt[s]++;
    }
    return 0;
}
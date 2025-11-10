#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    unordered_map<char, int> cnt;
    string s1, s2;
    cin >> s1 >> s2;
    for (auto& i : s1) {
        cnt[i]++;
    }
    for (auto& i : s2) {
        cnt[i]--;
        if (cnt[i] == 0) {
            cnt.erase(cnt.find(i));
        }
    }
    if (cnt.size() == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
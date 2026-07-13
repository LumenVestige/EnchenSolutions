#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct Node {
    int a, b, c;
};
void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> cnt;
    int tot = 0;
    vector<vector<Node>> data(m+1);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        data[b].push_back({a, b, c});
        if (cnt[a] == 0) tot++;
        cnt[a]++;
    }
    for (int i = 1; i <= m; ++i) {
        for (auto& it : data[i]) {
            cnt[it.a]--;
            if (cnt[it.a] == 0) tot--;
            if (cnt[it.c] == 0) tot++;
            cnt[it.c]++;
        }
        cout << tot << endl;
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
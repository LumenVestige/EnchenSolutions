#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node {
    int make, eat;
};
void solve() {
    int n;
    cin >> n;
    // 贪心
    vector<node> g;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g.push_back({a, b});
    }
    // 排序
    sort(g.begin(), g.end(), [&](node a, node b) {
        if (a.make != b.make) {
            return a.make < b.make;
        }
        return a.eat < b.eat;
    });
    int t = 0;
    for (int i = 0; i < g.size(); ++i) {
        t = max(t, g[i].make);
        t += g[i].eat;
    }
    cout << t << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
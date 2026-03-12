#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int rev(int n) {
    int r = 0;
    while (n != 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}
void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    queue<pair<int, int>> q; // 待操作数，操作次数
    bool vis[1000001];
    memset(vis, 0, sizeof(vis));
    int ans = -1;
    q.push({a, 0});
    vis[a] = true;
    while (!q.empty()) {
        auto [m, n] = q.front();
        q.pop();
        // 是否到达目标
        if (m == b) {
            ans = n;
            break;
        }
        // if (b-m > 0 && (b-m) % k == 0) {
        //     if (ans == -1) {
        //         ans = INT_MAX;
        //     }
        //     ans = min(ans, (b-m) / k + n);
        // }
        // 两个操作
        int t = rev(m), z = m+k;
        if (t <= 1e6 && !vis[t] && m % 10 != 0) {
            q.push({t, n+1});
            vis[t] = true;
        }
        if (z <= 1e6 && !vis[z]) {
            q.push({z, n+1});
            vis[z] = true;;
        }
    }
    cout << ans << endl;
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
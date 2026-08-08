#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        pq.push(t);
        ans -= t;
    } 

    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        if (pq.empty()) {
            ans += a;
            break;
        }
        int b = pq.top();
        pq.pop();
        int sum = a+b;
        ans += sum;
        pq.push(sum);
    }
    cout << ans;
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
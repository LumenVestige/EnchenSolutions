#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct BitTree {
    vector<int> tree;
    int n;
    BitTree(int x) : n(x), tree(x+1, 0) {}
    void add(int x, int val) {
        for (int i = x; i <= n; i += i & (-i)) {
            tree[i] += val;
        }
    }
    int query(int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= i&(-i)) {
            ans += tree[i];
        }
        return ans;
    }
};
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> cow(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cow[i] = {a, b};
    }
    sort(cow.begin(), cow.end());
    int cntTot = 0, sumTot = 0;
    BitTree cntL(2*1e4+2);
    BitTree sumL(2*1e4+2);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int v = cow[i].first;
        // cout << v << endl;
        int lCnt = cntL.query(cow[i].second), rCnt = cntTot - lCnt;
        int lSum = sumL.query(cow[i].second), rSum = sumTot - lSum;
        ans += v*(lCnt*cow[i].second - lSum + rSum - rCnt*cow[i].second);
        // cout << v*(lCnt*cow[i].second - lSum + rSum - rCnt*cow[i].second) << endl;
        // 添加当前牛到位置
        cntTot++, sumTot += cow[i].second;
        cntL.add(cow[i].second, 1);
        sumL.add(cow[i].second, cow[i].second);
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n, k;
vector<int> binaryTree;
void add(int x, int v) {
    for (; x <= n; x += x & -x) binaryTree[x] += v;
}
int query(int x) {
    int sum = 0;
    for (; x > 0; x -= x & -x) sum += binaryTree[x];
    return sum;
}
void solve() {
    cin >> n >> k;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    binaryTree.resize(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        add(i, abs(h[i] - h[i - 1]));
    }
    int ans = 1;
    for (int l = 1; l <= n; l++) {
        int lo = l, high = n, b = l;
        int base = query(l);
        while (lo <= high) {
            int mid = lo + (high - lo) / 2;
            if (query(mid) - base <= k) {
                b = mid;
                lo = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans = max(ans, b - l + 1);
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
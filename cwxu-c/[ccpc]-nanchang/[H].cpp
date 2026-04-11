#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // 1. 计算最晚加入时间 b[i]
    vector<int> b(n + 1);
    b[n] = a[n];
    for (int i = n - 1; i >= 1; --i) {
        b[i] = min(a[i], b[i + 1] - 1);
    }

    // 2. 检查合法性
    if (b[1] < 1) {
        cout << -1 << endl;
        return;
    }

    // 3. 贪心：让 p[1]=1, 其余 p[i]=b[i] 以最大化 p_i 从而减小总提升次数
    // 总提升次数 I = (a[1]-1) + sum_{i=2}^n (a[i]-b[i])
    int total_increments = (a[1] - 1);
    for (int i = 2; i <= n; ++i) {
        total_increments += (a[i] - b[i]);
    }

    // 最小操作数 = max(最后一次加入的时间, 加入次数 + 提升次数)
    int ans = max(a[n], n + total_increments);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
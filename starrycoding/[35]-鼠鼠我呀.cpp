//
// Created by sanenchen on 25-8-20.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> type(n + 1, 1), w(n + 1), prefix(n + 1);
    int ess = 0;
    for (int i = 1; i <= n; ++i)
        cin >> type[i];
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        ess += type[i] * w[i];
    }
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + (type[i] ? -1 : 1) * w[i];
    int fix = 0, mi = 0;
    // 最大子段和
    // fix = prefix[r] - prefix[l - 1];
    for (int i = 1; i <= n; ++i) {
        fix = max(fix, prefix[i] - mi);
        mi = min(mi, prefix[i]);
    }
    cout << ess + fix << '\n';




    // for (int i = 1; i <= n; ++i) {
    //     if (type[i] == 0)
    //         cin >> mice[i];
    //     else cin >> duck[i];
    // }
    //
    // // 计算前缀和
    // for (int i = 1; i <= n; ++i) {
    //     mice[i] = mice[i - 1] + mice[i];
    //     duck[i] = duck[i - 1] + duck[i];
    // }
    // int ess = duck[n], fix = 0;
    // // 区间交换枚举
    // int l = 0;
    // // for (int r = 1; r <= n; ++r) {
    // //     for (int l = 1; l <= r; ++l) {
    // //         // 比如交换 [3, 5] 区间
    // //         // 获取 1 2 区间的鸭鸭 3 4 5 区间的鼠鼠 6到以后得鸭鸭
    // //         ans_max = max(duck[l - 1] + mice[r] - mice[l - 1] + duck[n] - duck[r], ans_max);
    // //     }
    // // }
    // cout << ess + fix << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, x;
    cin >> n >> x;
    // vector<int> allow;
    // for (int i = 0; i <= x; ++i) {
    //     int tI = i, tX = x;
    //     bool flag = (i | x) == x;
    //     // while (tI != 0 && tX != 0) {
    //     //     if (((tX)&1) == 0 && ((tI)&1) == 1) {
    //     //         flag = true;
    //     //         break;
    //     //     }
    //     //     tI >>= 1, tX >>= 1;
    //     // }
    //     if (flag) {
    //         allow.push_back(i);
    //     }
    // }
    int idx = 0, idn = 0;
    int sum = 0;
    int last = -1;
    bool flag = false;
    while (idn < n) {
        // 一旦断了，直接报废
        if (flag) {
            cout << x << " ";
            idn++;
            continue;
        }
        if ((idx | x) != x || idx -1 != last) {
            flag = true;
            continue;
        }
        if (idn == n-1 && (sum | idx) != x) {
            // 如果是最后一个 sum 还没到达指标
            flag = true;
            continue;
        }
        cout << idx << " ";
        sum |= idx;
        last = idx;
        idx++, idn++;
    }
    cout << endl;
    // for (auto& i : allow) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // 不许重复，那就填充前面的，求或，之后后面挨个去弄
    // for (int i = 0; i < n-1; ++i) {
    //     sum |= allow[i];
    //     cout << allow[i] << " ";
    // }
    // // 最后一个数
    // for (int j = n-1; j < allow.size(); ++j) {
    //     int i = allow[j];
    //     if ((sum | i) == x) {
    //         cout << i << endl;
    //         return;
    //     }
    // }
    return;
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
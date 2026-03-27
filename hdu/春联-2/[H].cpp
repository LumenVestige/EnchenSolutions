#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    // 计算前缀和
    vector<int> z, prefix(n+1);
    int mi = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + nums[i];
        mi = min(mi, prefix[i]);
    }
    if (mi == 0) {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (mi == prefix[i]) {
            if (i == n) {
                cout << 1 << endl;
            } else {
                cout << i + 1 << endl;
            }
            return;;
        }
    }

    // for (auto& k : z) {
    //     bool is = true;
    //     for (auto i : z) {
    //         int flag = 0;
    //         if (i == k) continue;
    //         if (i == 1) {
    //             i = z[z.size()-1]-1;
    //         }
    //         if (check(k, i-1) < 0) {
    //             flag++;
    //         }
    //         if (flag != 0) {
    //             is = false;
    //             break;
    //         }
    //     }
    //     if (is) {
    //         cout << k << endl;
    //         return;
    //     }
    // }
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
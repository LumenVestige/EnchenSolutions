#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    int totCandy = 0;
    vector<int> nums(n);
    int zero = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        totCandy += t;
        nums[i] = t;
        zero += t == 0 ? 1 : 0;
    }
    if (totCandy % n != 0) {
        cout << "NO" << endl;
        return;
    }
    int K = totCandy / n;
    if (K > 1 && zero != 0) {
        cout << "NO" << endl;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (abs(nums[i] - K) > 1) {
            cout << "NO" << endl;
            return;
        }
    }
//     int right = 0, tmp = 0;
//     for (int i = n-1; i >= 0; --i) {
//         if (nums[i] != 0) {
//             tmp = max(tmp, nums[i]);
//         } else {
//             break;
//         }
//     }
//     while (right < n) {
//         // 右侧去探，遇到0
//         if (nums[right] == 0) {
//             if (tmp < 2) {
//                 cout << "NO" << endl;
//                 return;
//             }
//             tmp = 0;
//         }
//         tmp = max(tmp, nums[right++]);
//     }
//     cout << "YES" << endl;
    int lastStatus = -1;
    for (auto& i : nums) {
        if (abs(i-K) > 1) {
            cout << "NO" << endl;
            return;
        }
        if (i-K == -1) {
            if (lastStatus == 0) {
                cout << "NO" << endl;
                return;
            }
            lastStatus = 0;
        } else if (i-K == 1) {
            if (lastStatus == 1) {
                cout << "NO" << endl;
                return;
            }
            lastStatus = 1;
        }
    }
    cout << "YES" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
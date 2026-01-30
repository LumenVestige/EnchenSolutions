#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    if (cnt.size() == n) {
        for (int i = 0; i < k; ++i) {
            cout << nums[i] << " \n"[i+1 == n];
        }
    } else {
        int b = -1;
        int cur = 1;
        for (int i = 1; i <= n; ++i) {
            if (!cnt.count(i)) {
                b = i;
                break;
            }
        }
        cnt.clear();
        for (int i = 0; i < k; ++i) {
            if (i == 0) {
                cout << b << " ";
                cnt[b]++;
            } else if (i == 1) {
                for (int k = 1; k <= n; ++k) {
                    if (k != b && k != nums[n-1]) {
                        cout << k << " ";
                        cnt[k]++;
                        break;
                    }
                }
            } else {
                while (cnt.count(cur)) {
                    cur++;
                }
                cout << cur << " ";
                cnt[cur]++;
            }
        }
    }
    cout << endl;
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
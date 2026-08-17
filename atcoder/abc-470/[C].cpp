#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n+1, 0),act;
    int ans = 0;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int t; cin >> t;
            ans ^= (nums[t]++);
            ans ^= nums[t];
            if (nums[t] == 1) {
                act.push_back(t);
            }
        } else {
            vector<int> next;
            for (auto& id : act) {
                ans ^= (nums[id]--);
                if (nums[id] != 0) {
                    ans ^= nums[id];
                    next.push_back(id);
                } 
            }
            act = next;
        }
        cout << ans << endl;
    }
}

signed main() {
    // cout << (7 xor 3) << endl;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
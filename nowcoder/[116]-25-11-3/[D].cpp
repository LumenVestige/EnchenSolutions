#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
    int l;
    int r;
};
void solve() {
    int n;
    cin >> n;
    vector<Node> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].l >> nums[i].r;
    }
    Node allHave = nums[0];
    for (int i = 1; i < n; ++i) {
        auto& [l1, r1] = allHave;
        auto& [l2, r2] = nums[i];
        if ((l2 < l1 && r1 < r2 ) || (l1 < l2) && r2 < r1) {
            cout << "No" << endl;
            return;
        } else if (r1 < l2 || l1 > r2) {
            cout << "No" << endl;
            return;
        }
        if (l2 >= l1 && l2 <= r1) {
            l1 = l2;
        } else {
            l1 = max(l1, l2);
        }
        if (r2 >= r1 && r2 <= r1) {
            r1 = r2;
        } else {
            r1 = min(r1, r2);
        }
    }
    cout << "Yes" << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
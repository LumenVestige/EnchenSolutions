#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    unordered_map<int, int> cnt;
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int able1 = x;
    int able2 = n - y + 1;
    while (m--) {
        int tmp;
        cin >> tmp;
        if (cnt[tmp] == 0) {
            cnt[tmp] = 1;
        } else {
            cnt[tmp] = 0;
        }
        // 判断是否在目标区间
        if ((tmp >= 1 && tmp <= x)) {
            if (cnt[tmp] == 0) {
                able1++;
            } else {
                able1--;
            }
        } 
        if (tmp >= y && tmp <= n) {
            if (cnt[tmp] == 0) {
                able2++;
            } else {
                able2--;
            }
        }
        cout << able1 << " " << able2 << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
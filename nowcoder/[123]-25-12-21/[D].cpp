#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 998244353;
signed main() {
    int n;
    cin >> n;
    unordered_map<int, int> cards;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        cards[tmp]++;
    }
    int ans = 0;
    function<void(int)> dfs = [&](int n) {
        if (n == 0) {
            for (auto& [k, v] : cards) {
                if (v >= 3 && cards.count(k + 1) && cards[k + 1] >= 3) {
                    cards[k] -= 3, cards[k + 1] -= 3;
                    dfs(n + 1);
                    cards[k] += 3, cards[k + 1] += 3;
                }
            }
        } else {
            int tmpL2 = 0, other = 0;
            for (auto& [k, v] : cards) {
                if (v >= 2) {
                    tmpL2++;
                    if (v / 2 > 1) {
                        other++;
                    }
                }
            }
            int ansT = 1;
            ansT *= tmpL2 * (tmpL2 - 1);
            ans += ansT / 2;
            ans += other;
            ans %= mod;
        }
    };
    dfs(0);
    cout << ans % mod;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    long long ans = 0;
    for (int i = 0; i < 26; ++i) {
        if (!cnt[i]) continue;
        for (int j = i + 1; j < 26; ++j) {
            if (!cnt[j]) continue;
            for (int k = j + 1; k < 26; ++k) {
                if (!cnt[k]) continue;
                long long ways = cnt[i] * cnt[j] * cnt[k];
                ways %= MOD;
                ways = ways * 6 % MOD;
                ans += ways;
                if (ans >= MOD) ans -= MOD;
            }
        }
    }
    cout << ans % MOD << '\n';
    return 0;
}
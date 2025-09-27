#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    double sqrt_val = sqrt(2.0 * n);
    int k = (int)(sqrt_val + 0.5);
    
    int s_k = k * (k + 1) / 2;
    int s_k_1 = (k - 1) * k / 2;
    if (n > s_k) {
        k++;
    } else if (n <= s_k_1) {
        k--;
    }
    cout << k << endl;
}
signed main() {
    // cnt.emplace_back(1, 1);
    // cnt.emplace_back(2, 2);
    // cnt.resize(1e5);
    // for (int i = 2; i < 1e7; ++i) {
    //     pair<int, int> tmp = {cnt[i - 1].first + i, i + 1};
    //     cnt[i] = tmp;
    // }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
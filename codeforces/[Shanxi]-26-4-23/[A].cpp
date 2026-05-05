#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> c(n+1), w(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    vector<int> prefix(n+1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + w[i];
    }
    vector<int> dp(n+1, 1e18);
    for (int i = 1; i <= n; ++i) {
        pair<int, int> cM = {1e18, 1e18};
        
    }
    return 0;
}
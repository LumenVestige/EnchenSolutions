#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
unordered_map<int, int> cnt;
void init() {
    for (int i = 0; i < 11; i++) {
        cnt[i*(i+1)]++;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n; cin >> n;
    cout << (cnt[n] ? "YES" : "NO") << endl;
    return 0;
}
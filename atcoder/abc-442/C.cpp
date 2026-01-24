#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> reject;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        reject[a]++;
        reject[b]++;
    }
    for (int i = 1; i <= n; ++i) {
        int avi = n - 1 - reject[i];
        // cout << avi << " ";
        if (avi < 3) {
            cout << 0 << " ";
        } else {
            cout << avi * (avi - 1) * (avi - 2) / 6 << " ";
        }
    }
    return 0;
}
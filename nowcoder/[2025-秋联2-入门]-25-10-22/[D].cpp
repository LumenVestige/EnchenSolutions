#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
    int x = pow(a[0]-b[0], 2) + pow(a[1]-b[1], 2);
    int y = pow(a[0]-c[0], 2) + pow(a[1]-c[1], 2);
    int z = pow(c[0]-b[0], 2) + pow(c[1]-b[1], 2);
    if (x + y > z || x + z > y || y + z > x) {
        return true;
    }
    return false;
}

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> p;
    for (int i = 0 ;i < n; ++i) {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int z = j + 1; z < n; ++z) {
                if (check(p[i], p[j], p[z])) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    int times = 1;
    while (t--) {
        int l, r;
        cin >> l >>r;
        times *= (r - l + 1);
    }
    if (times > 1e7) {
        cout << "TLE";
    } else if (times <= 1e5) {
        cout << "NO TLE";
    } else {
        cout << "POSSIBLE";
    }
    return 0;
}
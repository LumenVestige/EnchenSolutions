#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    // 取出最后一位
    int t = n % 10;
    if (t == 0) {
        cout << 1;
        return 0;
    }
    if (t == 2) {
        cout << 5;
    } else if (t == 4 || t == 8 || t == 6) {
        cout << 5;
    } else if (t == 5) {
        cout << 2;
    } else {
        cout << 10;
    }
    return 0;
}
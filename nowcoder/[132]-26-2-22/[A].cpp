#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n + 5 >= 24) {
        cout << n + 5 - 24;
    } else {
        cout << n;
    }
    return 0;
}
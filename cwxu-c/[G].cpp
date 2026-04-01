#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(int n) {
    switch (n) {
        case 3:
        case 5:
            cout << 1 << endl;
            return ;
        case 1:
        case 4:
        case 2:
            cout << -1 << endl;
            return;
    }
    int base = n / 6 * 2;
    int add = n % 6;
    switch (add) {
        case 0:
            cout << base << endl;
            return;
        case 1:
            cout << base-1 << endl;
            return;
        case 2:
            cout << base << endl;
            return;
        case 3:
            cout << base+1 << endl;
            return;
        case 4:
            cout << base << endl;
            return;
        case 5:
            cout << base+1 << endl;
            return;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    if (x*x > x) {
        cout << "right";
    } else if (x*x < x) {
        cout << "left";
    } else {
        cout << "equal";
    }
    return 0;
}
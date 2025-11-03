#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if ((l2 < l1 && r1 < r2 ) || (l1 < l2) && r2 < r1) {
        cout << "A";
    } else if (r1 < l2 || l1 > r2) {
        cout << "B";
    } else cout << "C";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}
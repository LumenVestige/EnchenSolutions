#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int c = x1 * y2 - x2 * y1;
    if (y1-y2 == 0) {
        if (abs(c) == 4) {
            cout << 0 << endl;
        } else 
            cout << "no answer" << endl;
    } else {
        long double x = 1.0 * (4 - c) / (y1 - y2);
        cout << fixed << setprecision(6)<< x << endl;
    }
    return 0;
}
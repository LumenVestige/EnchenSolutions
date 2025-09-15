//
// Created by sanenchen on 25-9-14.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2) {
        long long len = abs(x1 - x2);
        x3 = x1;
        y3 = y1 + len + 1;
    } else if (x1 == x2) {
        long long len = abs(y1 - y2);
        x3 = x1 + len + 1;
        y3 = y1;
    } else {
        long long h = abs(x1 - x2);
        x3 = x1;
        y3 = y1 + h + 1;
    }
    cout << x3 << " " << y3;
    return 0;
}

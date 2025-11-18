#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
long double pi = 3.1415926535897932384689433;
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    int p1, p2;
    cin >> p1 >> p2;
    int times = min(abs(p1 - p2), n - abs(p2 - p1));
    long double oneTime = 1.0 * 2 * r * sin(1.0 * M_PI / n);
    long double ans = times * oneTime;
    printf("%Lf", ans);
    return 0;
}
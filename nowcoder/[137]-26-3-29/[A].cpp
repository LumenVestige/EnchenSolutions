#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    
    int a = t / 3600;
    t %= 3600;
    int b = t / 60;
    t %= 60;
    int c = t;
    printf("%lld %lld %lld", a, b, c);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,l,r;
    cin >>a>>b>>c>>l>>r;
    int ans = r-l;
    unordered_set<int> sr;
    if (a >= l && a <= r) {
        sr.insert(a);
    }
    if (b >= l && b <= r) {
        sr.insert(c);
    }
    if (c >= l && c <= r) {
        sr.insert(c);
    }
    cout << ans - sr.size();
    return 0;
}
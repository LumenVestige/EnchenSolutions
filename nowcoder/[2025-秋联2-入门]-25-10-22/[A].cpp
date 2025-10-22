#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int A, B, C;
    int X, Y, Z;
    cin >> A >> B >> C >> X >> Y >> Z;
    int ans = 0;
    ans += min(A, Y);
    ans += min(B, Z);
    ans += min(C, X);
    cout << ans;
    return 0;
}
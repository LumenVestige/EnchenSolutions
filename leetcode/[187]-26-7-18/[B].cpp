#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
long long maximumValue(int n, int s, int m) {
    int last = s;
    int times = 1;
    int ans = s;
    for (int i = 1; i < n; ++i) {
        if (i % 2 != 0) {
            last = last + m;
        } else {
            last--;
        }
        ans = max(ans, last);
    }
    return ans;
}
int check(int n, int s, int m) {
    if (n == 1) {
        return s;
    }
    return s + (m-1)*(n/2)+1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 1000; ++i) {
        cout << i << " " << maximumValue(i, 4, 5) << " " << check(i, 4, 5) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >>n;
    string s;
    cin >> s;
    int mid = n/2;
    for (int i = 0 ; i < n; ++i) {
        if (s[i] == '?') {
            if (i < mid) {
                s[i] = 'L';
            } else {
                s[i] = 'Q';
            }
        }
    }
    vector<int> afterFix(n+1, 0);
    int ans = 0;
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == 'Q') {
            afterFix[i]++;
        }
        afterFix[i] += afterFix[i+1];
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            ans += afterFix[i];
        }
    }
    cout << ans;
    return 0;
}
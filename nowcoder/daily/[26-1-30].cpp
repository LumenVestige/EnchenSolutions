#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int m = nums[0];
    for (int i = 1; i < n; ++i) {
        m = gcd(m, nums[i]);
    }
    cout << m*n;
    return 0;
}
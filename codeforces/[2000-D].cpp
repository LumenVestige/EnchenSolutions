#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    string s;
    cin >> s;
    // 计算一下前缀和
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    int left = 0, right = n - 1;
    int ans = 0;
    while (right >= left) {
        if (s[left] != 'L') {
            left++;
        }
        if (s[right] != 'R') {
            right--;
        }
        if (s[left] == 'L' && s[right] == 'R') {
            ans += prefix[right + 1] - prefix[left];
            left++;
            right--;
        }
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
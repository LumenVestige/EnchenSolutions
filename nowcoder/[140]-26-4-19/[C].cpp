#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m-1; ++j) {
            unordered_set<char> s;
            s.insert(nums[i][j]);
            s.insert(nums[i][j+1]);
            s.insert(nums[i+1][j]);
            s.insert(nums[i+1][j+1]);
            if (s.size() == 3) {
                ans += 2;
            }
        }
    }
    cout << ans;
    return 0;
}
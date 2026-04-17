#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> nums(n+1);
    for (int i = 1; i < n; ++i) {
        int t;
        cin >> t;
        nums[t].push_back(i+1);
    }
    vector<int> cnt(n+1);
    auto dfs = [&](auto&& dfs, int pos) {
        if (nums[pos].size() == 0) {
            cnt[pos] = 1;
            return;
        }
        for (auto& i : nums[pos]) {
            dfs(dfs, i);
            cnt[pos] += cnt[i]; // 儿子们加进去
        }
        cnt[pos]++;
    };
    dfs(dfs, 1);
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << " ";
    }
    return 0;
}
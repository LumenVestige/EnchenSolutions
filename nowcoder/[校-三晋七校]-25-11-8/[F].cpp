#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, q;
    cin >> n >>q;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    vector<unordered_map<int, int>> vec(n + 1);
    unordered_map<int, pair<int, int>> ans; // first是k second是times
    // for (int j = 1; j <= n; ++j) {
    //     vec[0][nums[j] * 2]++;
    // }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            vec[i][nums[j] + nums[(j - i + n) % n + 1]]++;
            //cout << nums[(j - i + n) % n + 1] << " ";
        }
        //cout << endl;
    }
    for (int i = 1; i < n; ++i) {
        for (auto& [k, v] : vec[i]) {
            if (!ans.count(k)) {
                ans[k] = {0, 0};
            }
            if (ans[k].second < v) {
                ans[k] = {i, v};
            }
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (ans[t].first == 0) cout << 0 << endl;
        else cout << ans[t].first - 1 << endl;
    }
    return 0;
}
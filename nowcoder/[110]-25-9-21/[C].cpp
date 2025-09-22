//
// Created by sanenchen on 25-9-21.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> findMax(vector<int>& nums) {
    // 找到所有最大值的位置
    int m = INT_MIN;
    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < nums.size(); ++i) {
        pos[nums[i]].push_back(i);
        m = max(m, nums[i]);
    }
    return pos[m];
}
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    // 找到最大值列表
    auto maxList = findMax(nums);
    int ans = INT_MIN;
    for (auto& i : maxList) { // i是下标
        if ((i != nums.size() - 1 && nums[i + 1] != 0 ) || (i != 0 && nums[i - 1] != 0)) {
            ans = max(nums[i], ans);
            //break;
        }
        else if (nums[i] == 1) ans = max(nums[i] - 2, ans);
        else ans = max(nums[i] - 1, ans);
    }
    cout << ans << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
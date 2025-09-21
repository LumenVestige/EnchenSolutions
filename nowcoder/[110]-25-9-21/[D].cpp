//
// Created by sanenchen on 25-9-21.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int sumAns(vector<int>& nums) {
    int ans = 0;
    // 计算中位数
    int mid = (nums.size() % 2 == 0) ? nums[nums.size() / 2 - 1] : nums[nums.size() / 2];
    for (auto& i : nums) {
        ans += abs(i - mid);
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    // 先排序
    sort(nums.begin(), nums.end());
    // 其实就两个选择 一个是选择当前中位数左边的 一个是选择当前中位数右边的
    // 选择左边的就要删掉与新中位数差距最大的
    vector<int> numL(nums.begin() + 1, nums.end()), numR(nums.begin(), nums.end() - 1);
    int ans = min(sumAns(numL), sumAns(numR));
    cout << ans << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
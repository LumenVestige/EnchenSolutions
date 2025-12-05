#include <bits/stdc++.h>
using namespace std;
#define int long long
// 二分查找
int lowerBound(vector<int>& nums, int target) {
    int left = -1, right = nums.size();
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, vector<int>> pos; // 这个将会记录对应的出现位置
    // 我将会采取二分查找方式
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        pos[nums[i]].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto& numPos = pos[nums[i]];
        auto thePosIter = lower_bound(numPos.begin(), numPos.end(), i);
        int thePos = thePosIter - numPos.begin();
        ans += n - (i + 1) - (numPos.size() - (thePos + 1));
    }
    cout << ans;
    return 0;
}
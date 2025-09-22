#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    // 排序
    sort(nums.begin(), nums.end());
    // 平方
    for (auto& i : nums)
        i *= i;
    // 定长滑动窗口
    int ans = INT_MAX, left = 0, tmp = 0;
    for (int right = 0; right < n - 1; ++right) {
        // 怎么把差放进去？ 三步走 入 判断 出
        tmp += abs(nums[right] - nums[right + 1]);
        if (right + 2 < k) continue;
        ans = min(tmp, ans);
        tmp -= abs(nums[left] - nums[left + 1]);
        left++;
    }
    cout << ans;
    return 0;
}
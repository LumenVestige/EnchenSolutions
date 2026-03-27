#include <bits/stdc++.h>
using namespace std;
vector<int> calc(vector<int> nums) {
    int n = nums.size();
    vector<int> pre(n);
    pre[0] = 1;
    pre[1] = 2;
    for (int i = 2; i < n; ++i) {
        if (nums[i] + nums[i-2] == nums[i-1]*2) {
            pre[i] = pre[i-1] + 1;
        } else {
            pre[i] = 2;
        }
    }
    return pre;
}

int longestArithmetic(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre, suf;
    pre = calc(nums);
    auto t = nums;
    reverse(t.begin(), t.end());
        suf = calc(t);
    reverse(suf.begin(), suf.end());

    int ans = *max_element(pre.begin(), pre.end()) + 1;
    if (ans >= n) {
        return n;
    }
    for (int i = 1; i < n - 1; ++i) {
        // 将要修改第i个数字
        int d2 = nums[i+1] - nums[i-1];
        if (d2%2) {
            continue;
        }
        bool ok_left = i > 1 && nums[i-1] - nums[i-2] == d2/2;
        bool ok_right = i + 2 < n && nums[i+2] - nums[i+1] == d2/2;
        if (ok_left && ok_right) {
            ans = max(ans, pre[i-1] + 1 + suf[i+1]);
        } else if (ok_left) {
            ans = max(ans, pre[i-1]+2);
        } else if (ok_right) {
            ans = max(ans, suf[i+1]+2);
        }
    }
    return ans;
}
int main() {
    vector<int> nums = {9,7,5,10,1};
    cout << longestArithmetic(nums);
    return 0;
}
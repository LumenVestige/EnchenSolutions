#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 枚举中间的j
long long maximumTripletValue(vector<int>& nums) {
    // 预处理右边的最大值
    ll n = nums.size(), tmp = INT_MIN;
    vector<ll> mxRight(n, 0), mxLeft(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        mxRight[i] = max((ll)nums[i], tmp);
        tmp = mxRight[i];
    }
    mxLeft[0] = nums[0];
    tmp = nums[0];
    ll ans = INT_MIN;
    // 枚举中间j
    for (int i = 1; i < n - 1; ++i) {
        ans = max(ans, (mxLeft[i - 1] - nums[i]) * mxRight[i + 1]);
        mxLeft[i] = max(tmp, (ll)nums[i]);
        tmp = mxLeft[i];
    }
    return ans < 0 ? 0 : ans;
}
// 先枚举 j 维护i 再枚举k 维护(i, j)
long long maximumTripletValue2(vector<int>& nums) {
    ll n = nums.size(), tmp = nums[0];
    vector<ll> mp1(n, INT_MIN);
    // 预处理 i - j
    for (int i = 1; i < n - 1; ++i) {
        mp1[i] = max(mp1[i - 1], tmp - nums[i]);
        tmp = max(tmp, (ll)nums[i]);
    }
    ll ans = 0;
    // 处理一下 k
    for (int i = 2; i < n; ++i) {
        ans = max(ans, mp1[i - 1] * nums[i]);
    }
    return ans < 0 ? 0 : ans;
}
int main() {
    vector<int> nums = {12,6,1,2,7};
    cout << maximumTripletValue2(nums);
    return 0;
}
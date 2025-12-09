#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int specialTriplets(vector<int>& nums) {
    int ans = 0;
    map<int, ll> mp1, mp2;
    for (auto& i : nums) {
        if ((i & 1) == 0 && mp2.count(i / 2)) {
            ans += mp2[i / 2] % (long long)(1e9 + 7);
            ans %= (ll)(1e9 + 7);
        }
        if (mp1.count(i * 2)) mp2[i] += mp1[2 * i];
        mp1[i]++; // 数字i计数
    }
    return ans % (long long)(1e9 + 7);
}
int main() {
    vector<int> nums = {6,3,6};
    cout << specialTriplets(nums);
    return 0;
}
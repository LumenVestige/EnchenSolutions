#include <bits/stdc++.h>
using namespace std;
long long maxProduct(vector<int>& nums) {
    // 每个数求绝对值
    for (auto& i : nums) {
        i = abs(i);
    }
    sort(nums.begin(), nums.end());
    long long ans = (long long)nums[nums.size() - 1] * (long long)nums[nums.size() - 2] * 1e5;
    return ans;
}
int main() {
    vector<int> nums = {-5, 7, 0};
    cout << maxProduct(nums);
    return 0;
}
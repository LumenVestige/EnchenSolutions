#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums) {
    int ans = 0;
    vector<int> prefix(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); ++i) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    for (int i = 0; i < nums.size(); ++i) {
        int pos = max(0, i - nums[i]);
        ans += prefix[i + 1] - prefix[pos];
    }
    return ans;
}
int main() {
    vector<int> nums = {2, 3, 1};
    cout << subarraySum(nums);
    return 0;
}
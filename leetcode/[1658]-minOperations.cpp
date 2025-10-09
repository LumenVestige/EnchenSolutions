#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums, int x) {
    int sum = 0;
    for (auto& i : nums) 
        sum += i;
    int target = sum - x;
    if (target == 0) return nums.size();
        if (target < 0) return -1;
    int l = 0, ans = -1, tmp = 0;
    for (int r = 0; r < nums.size(); ++r) {
        tmp += nums[r];
        while (tmp > target && r > l) {
            tmp -= nums[l];
            l++;
        }
        if (tmp == target) 
            ans = max(ans, r - l + 1);
    }
    if (nums.size() - ans > nums.size()) return 0;
    return nums.size() - ans;
}
int main() {
    vector<int> nums = {1, 1, 4, 2, 3};
    cout << minOperations(nums, 5);
    return 0;
}
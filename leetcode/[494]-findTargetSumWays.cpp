#include <bits/stdc++.h>
using namespace std;

int sumSubSet(vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (auto& i : nums) {
        sum += i;
    }
    if (sum < abs(target) || (sum + target) % 2 == 1) {
        return 0;
    }
    return sumSubSet(nums, (sum + target) / 2);
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3);
    return 0;
}
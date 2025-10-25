#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if (sum % 2 == 1) {
        return false;
    }
    int n = nums.size(), t = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, false));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= t; ++j) {
            if (j - nums[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][t];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);
    return 0;
}
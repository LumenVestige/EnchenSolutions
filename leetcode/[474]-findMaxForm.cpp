#include <bits/stdc++.h>
using namespace std;

int count(string& str, char tar) {
    int ans = 0;
    for (auto& i : str) {
        ans += (i == tar) ? 1 : 0;
    }
    return ans;
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
    for (int i = 0; i < strs.size(); ++i) {
        int cnt0 = count(strs[i], '0');
        int cnt1 = strs[i].size() - cnt0;
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (cnt0 <= j && cnt1 <= k) {
                    dp[i + 1][j][k] = max(dp[i][j][k], dp[i][j - cnt0][k - cnt1] + 1);
                } else {
                    dp[i + 1][j][k] = dp[i][j][k];
                }
            }
        }
    }
    return dp[strs.size()][m][n];
}

int main() {
    vector<string> nums = {"10","0001","111001","1","0"};
    cout << findMaxForm(nums, 5, 3);
    return 0;
}
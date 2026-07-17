#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        constexpr int MOD = 1'000'000'007;
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector memo(n, vector(m + 1, vector<int>(m + 1, -1))); // -1 表示没有计算过

        auto dfs = [&](auto&& dfs, int i, int j, int k) -> int {
            if (i < 0) {
                return j == k;
            }
            int& res = memo[i][j][k];
            if (res < 0) {
                res = ((long long) dfs(dfs, i - 1, j, k) +
                       dfs(dfs, i - 1, gcd(j, nums[i]), k) +
                       dfs(dfs, i - 1, j, gcd(k, nums[i]))) % MOD;
            }
            return res;
        };
        return (dfs(dfs, n - 1, 0, 0) - 1 + MOD) % MOD; 
    }
};

int main() {
    const int CASE = 1;

    vector<int> nums;
    if (CASE == 1) {
        nums = {1, 2, 3, 4};
    } else if (CASE == 2) {
        nums = {10, 20, 30};
    } else {
        nums = {1, 1, 1, 1};
    }
    cout << Solution().subsequencePairCount(nums) << endl;
    return 0;
}
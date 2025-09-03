//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>

using namespace std;

long long maxSum(vector<int> &nums, int m, int k) {
    unordered_map<int, int> hash_map;
    long long ans = 0, prefix = 0, already = 0;
    for (int i = 0; i < nums.size(); ++i) {
        // 入
        // 判断是否已经存在
        already += (hash_map[nums[i]] != 0) ? 1 : 0;
        hash_map[nums[i]]++;
        prefix += nums[i];
        if (i + 1 < k) continue;
        // 更新
        cout << already << endl;
        if (already <= k - m)
            ans = max(ans, prefix);
        // 出
        prefix -= nums[i - k + 1];
        already -= (hash_map[nums[i - k + 1]] > 1) ? 1 : 0;
        hash_map[nums[i - k + 1]]--;
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 1, 4, 3};
    cout << maxSum(nums, 2, 2);
    return 0;
}

//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> getAverages(vector<int> &nums, int k) {
    vector<int> ans(nums.size(), -1);
    // 覆写 k k = 2 * k + 1;
    k = 2 * k + 1;
    long long sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        // 入
        sum += nums[i];
        if (i + 1 < k) continue;
        // 更新
        ans[i - k / 2] = sum / k;
        // 出
        sum -= nums[i - k + 1];
    }
    return ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    vector<int> nums = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    for (auto &it: getAverages(nums, 3))
        cout << it << " ";
    cout << endl;
    return 0;
}

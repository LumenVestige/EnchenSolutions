//
// Created by sanenchen on 25-10-26.
//
#include <bits/stdc++.h>
using namespace std;

long long maxAlternatingSum(vector<int>& nums) {
    // 首先全部变为正数
    for (auto& i : nums) {
        i = abs(i);
    }
    // 先排序
    sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
        return a > b;
    });
    long long ans = 0;
    int n = nums.size() - 1;
    // 0 - n / 2 +
    // n / 2 + 1 - n -
    for (int i = 0; i <= n / 2; ++i) {
        ans += pow(nums[i], 2);
    }
    for (int i = n / 2 + 1; i <= n; ++i) {
        ans -= pow(nums[i], 2);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << maxAlternatingSum(nums);
    return 0;
}
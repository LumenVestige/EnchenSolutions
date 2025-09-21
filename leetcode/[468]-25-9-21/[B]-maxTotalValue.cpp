//
// Created by sanenchen on 25-9-21.
//
#include <bits/stdc++.h>
using namespace std;

long long maxTotalValue(vector<int>& nums, int k) {
    int t;
    // 找到最大值 最小值
    int nMax = INT_MIN, nMin = INT_MAX;
    for (auto& i : nums) {
        nMax = max(nMax, i);
        nMin = min(nMin, i);
    }
    t = nMax - nMin;
    long long ans = t * k;
    return ans;
}

int main() {
    vector<int> nums = {11, 8};
    cout << maxTotalValue(nums, 2);
    return 0;
}
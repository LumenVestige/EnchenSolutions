//
// Created by sanenchen on 25-9-22.
//
#include <bits/stdc++.h>
using namespace std;
int maxFrequencyElements(vector<int> &nums) {
    // 构建一个 hashmap
    unordered_map<int, int> m;
    for (auto &i : nums)
        m[i]++;
    int tmp = 0;
    for (auto &i : m)
        tmp = max(tmp, i.second);
    int ans = 0;
    for (auto& i : m)
        if (i.second == tmp) ans += tmp;
    return ans;
}
int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    cout << maxFrequencyElements(nums);
    return 0;
}
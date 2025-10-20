//
// Created by sanenchen on 25-10-18.
//
#include <bits/stdc++.h>
using namespace std;

int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int cnt = 0, prev = INT_MIN;
    for (auto& i : nums) {
        int current = min(max(i - k, prev + 1), i + k);
        if (current > prev) {
            cnt++;
            prev = current;
        }
    }
    return cnt;
}

int main() {
    vector<int> nums = {1,2,2,3,3,4};
    cout << maxDistinctElements(nums, 2);
    return 0;
}
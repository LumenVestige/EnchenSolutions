//
// Created by sanenchen on 25-10-25.
//
#include <bits/stdc++.h>
using namespace std;

// int change(int a, int b) {
//
// }

long long minOperations(vector<int> &nums1, vector<int> &nums2) {
    int ans = 1;
    // 找一个差值最小的压进去
    int m = INT_MAX;
    int target = nums2[nums2.size() - 1];
    for (const int j : nums1) {
        m = min(m, abs(j - nums2[nums2.size() - 1]));
    }
    for (int i = 0; i < nums1.size(); ++i) {
        if ((nums1[i] >= target && nums1[i] - nums2[i] < 0 && nums2[i] <= target ||
             (nums1[i] <= target && nums1[i] - nums2[i] > 0 && nums2[i] >= nums2[nums2.size()])))
            m = 0;
        m = min(m, abs(nums2[i] - nums2[nums2.size() - 1]));
    }
    for (int i = 0; i < nums1.size(); ++i) {
        ans += abs(nums2[i] - nums1[i]);
    }
    ans += m;
    return ans;
}

int main() {
    vector<int> nums1 = {2};
    vector<int> nums2 = {3, 4};
    cout << minOperations(nums1, nums2);
    return 0;
}
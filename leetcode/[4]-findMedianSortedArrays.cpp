//
// Created by sanenchen on 25-8-4.
//
#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    for (auto &target: nums2) {
        int l = -1, r = nums1.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums1[mid] >= target)
                r = mid;
            else
                l = mid;
        }
        nums1.insert(nums1.begin() + r, target);
    }
    // for (auto& it : nums1) {
    //     cout << it << " ";
    // }
    if (nums1.size() % 2 == 0) {
        return double(nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2;
    }
    return nums1[nums1.size() / 2];
}

int main() {
    vector<int> n1 = {1, 3};
    vector<int> n2 = {2};
    cout << findMedianSortedArrays(n1, n2);

    return 0;
}

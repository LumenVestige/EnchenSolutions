//
// Created by sanenchen on 25-8-15.
//
#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr2, int target) {
    int left = -1, right = arr2.size();
    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (arr2[mid] >= target)
            right = mid;
        else left = mid;
    }
    return right;
}

int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    int ans = 0;
    // 先给arr2来个大保健
    sort(arr2.begin(), arr2.end());
    for (auto& it : arr1) {
        int targetPositive = it - d;
        int targetNegative = it + d;
        // 一个区间 不可以的区间是 [t1, t2]
        int lowerBound = search(arr2, targetPositive);
        if (lowerBound < arr2.size() && arr2[lowerBound] <= targetNegative)
            continue;
        ans++;
    }
    return ans;
}

int main() {
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    cout << findTheDistanceValue(arr1, arr2, 2);
    return 0;
}

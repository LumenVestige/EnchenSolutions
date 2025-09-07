//
// Created by sanenchen on 25-8-14.
//
#include <bits/stdc++.h>
using namespace std;

// 暴力遍历 时间复杂度O(n)
// int peakIndexInMountainArray(vector<int>& arr) {
//     int peakTmp = arr[0];
//     for (int i = 1; i < arr.size(); ++i) {
//         if (peakTmp > arr[i]) {
//             return i - 1;
//         }
//         peakTmp = arr[i];
//     }
//     return 0;
// }
// 二分法 时间复杂度 O(loh(n))
int peakIndexInMountainArray(vector<int> &arr) {
    // 瞎写的二分
    // int left = 0, right = arr.size() - 1;
    // int mid = (left + right) / 2;
    // while (!(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])) {
    //     if (arr[mid] > arr[mid - 1])
    //         left = mid;
    //     else right = mid;
    //     mid = (left + right) / 2;
    // }
    // return mid;
    // 标准的二分
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        else right = mid;
    }
    return left;
}


int main() {
    vector<int> arr = {3, 5, 3, 2, 0};
    cout << peakIndexInMountainArray(arr);
    return 0;
}

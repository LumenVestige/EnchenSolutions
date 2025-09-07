//
// Created by sanenchen on 2025/9/3.
//
#include <bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int ans = 0, sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        // 入
        sum += arr[i];
        // 是否形成了目标窗口
        if (i + 1 < k)
            continue;
        // 更新答案
        if (1.0 * sum / k >= threshold) {
            ans++;
        }
        // 出
        int out = arr[i - k + 1];
        sum -= out;
    }
    return ans;
}

int main() {
    vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    cout << numOfSubarrays(arr, 3, 5);
    return 0;
}

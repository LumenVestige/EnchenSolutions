//
// Created by sanenchen on 25-9-15.
//
#include <bits/stdc++.h>
using namespace std;
// 小顶堆暴力做法
// int kthSmallest(vector<vector<int>>& matrix, int k) {
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for (auto& i : matrix) {
//         for (auto& j : i) {
//             pq.push(j);
//         }
//     }
//     k -= 1;
//     while (k--) {
//         pq.pop();
//     }
//     return pq.top();
// }

// 二分套二分
int kthSmallest(vector<vector<int> > &matrix, int k) {
    auto check = [&](int mid)-> bool {
        int cnt = 0;
        int h = 0, r = matrix.size() - 1;
        // 二维的二分查找
        while (r >= 0 && h < matrix.size()) {
            if (matrix[h][r] <= mid) {
                cnt += r + 1;
                h++;
            } else {
                r--;
            }
        }
        return cnt >= k;
    };
    // 找到最K小的数
    int left = matrix[0][0] - 1, right = matrix[matrix.size() - 1][matrix.size() - 1];
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    vector<vector<int> > matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << kthSmallest(matrix, 8);
    return 0;
}

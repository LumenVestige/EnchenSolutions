//
// Created by sanenchen on 25-8-20.
//
#include <bits/stdc++.h>
using namespace std;

bool check(int x1, int y1, int x2, int y2, int target) {
    // 计算理论数字
    int need = (y2 - y1 + 1) * (x2 - x1 + 1);
    return need == target;
}

int numSubmat(vector<vector<int> > &matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    // 使用二维数组存储前缀和，访问速度远快于哈希表
    vector<vector<int>> prefix(rows, vector<int>(cols, 0));
    prefix[0][0] = matrix[0][0];
    for (int i = 1; i < matrix.size(); ++i) {
        prefix[i][0] = prefix[i - 1][0] + matrix[i][0];

    }
    for (int j = 1; j < matrix[0].size(); ++j) {
        prefix[0][j] = prefix[0][j - 1] + matrix[0][j];
    }
    // 剩余的前缀和
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            prefix[i][j] = matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    // 遍历每一个数 向右下角扩展正方形
    int ans = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            int n = matrix[0].size();
            for (int e = i; e < matrix.size(); ++e) {
                for (int r = j; r < n; ++r) {
                    int target = prefix[e][r] - prefix[e][j - 1] - prefix[i - 1][r] + prefix[i - 1][j - 1];
                    if (check(i, j, e, r, target)) {
                        ans++;
                    } else {
                        n = r + 1;
                        break;
                    }
                }
            }
            // int e = i, r = j;
            // while (e < matrix.size() && r < matrix[0].size()) {
            //     int target = prefix[e][r] - prefix[e][j - 1] - prefix[i - 1][r] + prefix[i - 1][j - 1];
            //     if (check(i, j, e, r, target)) {
            //         ans++;
            //     } else break;
            //     e++;
            //     r++;
            // }
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > nums = {
        {1,0,1},
        {1,1,0},
        {1,1,0}
    };
    cout << numSubmat(nums);
    return 0;
}

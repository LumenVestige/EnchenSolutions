//
// Created by sanenchen on 25-8-20.
//
#include <bits/stdc++.h>
using namespace std;

bool check(int x1, int y1, int x2, int y2, int target) {
    // 计算理论数字
    int need = pow(y2 - y1 + 1, 2);
    return need == target;
}

int countSquares(vector<vector<int> > &matrix) {
    unordered_map<int, unordered_map<int, int> > prefix;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            prefix[i][j] = matrix[i][j];
        }
    }
    // 剩余的前缀和
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            prefix[i][j] = prefix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    // 遍历每一个数 向右下角扩展正方形
    int ans = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            int e = i, r = j;
            while (e < matrix.size() && r < matrix[0].size()) {
                int target = prefix[e][r] - prefix[e][j - 1] - prefix[i - 1][r] + prefix[i - 1][j - 1];
                if (check(i, j, e, r, target)) {
                    ans++;
                } else break;
                e++;
                r++;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > nums = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    cout << countSquares(nums);
    return 0;
}

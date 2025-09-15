//
// Created by sanenchen on 25-9-15.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int> > &mat) {
    vector<int> ans;
    int h = 0, r = 0, flag = 0;
    while (h != mat.size() && r != mat[0].size()) {
        // 把当前这个数压进去
        ans.push_back(mat[h][r]);
        // 如果是上升阶段
        if (flag == 0) {
            // 判断是否升完之后超出范围
            if (h - 1 < 0 || r + 1 >= mat[0].size()) {
                // 优先右侧
                if (r + 1 < mat[0].size()) r++;
                else h++;
                flag = 1; // 转为下降阶段
            } else {
                h--;
                r++;
            }
        } else {
            // 下降阶段
            // 判断是否降完之后超出范围
            if (h + 1 >= mat.size() || r - 1 < 0) {
                // 优先下侧
                if (h + 1 < mat.size()) h++;
                else r++;
                flag = 0; // 转为上升阶段
            } else {
                h++;
                r--;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (auto &i: findDiagonalOrder(mat)) {
        cout << i << " ";
    }
    return 0;
}

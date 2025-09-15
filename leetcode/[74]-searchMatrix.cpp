//
// Created by sanenchen on 25-9-15.
//
#include <bits/stdc++.h>
using namespace std;
// 双指针法 (排除法)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int h = 0, r = matrix[0].size() - 1;
    while (h < matrix.size() && r >= 0) {
        if (matrix[h][r] == target) return true;
        if (matrix[h][r] >= target) r--;
        else h++;
    }
    return false;
}
int main() {
    vector<vector<int>> matrix = {{1,3}};
    cout << searchMatrix(matrix, 3);
    return 0;
}
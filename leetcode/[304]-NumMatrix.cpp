//
// Created by sanenchen on 25-8-19.
//
#include <bits/stdc++.h>
using namespace std;
class NumMatrix {
private:
    unordered_map<int, unordered_map<int, int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (i == 0 && j == 0) {
                    prefix[0][0] = matrix[0][0];
                    continue;
                }
                if (i == 0) {
                    prefix[i][j] = prefix[i][j - 1] + matrix[i][j];
                    continue;
                }
                if (j == 0) {
                    prefix[i][j] = prefix[i - 1][j] + matrix[i][j];
                    continue;
                }
                prefix[i][j] = matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2][col2] - prefix[row2][col1 - 1] - prefix[row1 - 1][col2] + prefix[row1 - 1][col1 - 1];
    }
};

int main() {
    vector<vector<int>> nums = {{-1}};
    NumMatrix num_matrix(nums);
    cout << num_matrix.sumRegion(0,0,0,0);
    return 0;
}
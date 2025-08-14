//
// Created by sanenchen on 25-8-14.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > transpose(vector<vector<int> > &matrix) {
    size_t column = matrix.size(), row = matrix[0].size();
    vector<vector<int>> ans;
    for (int i = 0; i < row; ++i) {
        vector<int> tmp;
        for (int j = 0; j < column; ++j) {
            tmp.push_back(matrix[j][i]);
        }
        ans.push_back(tmp);
    }
    return ans;
}

int main() {
    vector<vector<int> > mx = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    transpose(mx);
    return 0;
}

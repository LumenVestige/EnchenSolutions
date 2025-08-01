//
// Created by sanenchen on 25-8-1.
//
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back(vector(1,1));
    for (int i = 2; i <= numRows; ++i) {
        vector<int> tmp;
        for (int j = 0; j < i; ++j) {
            if (j == 0 || j == i - 1) {
                tmp.push_back(1);
            } else {
                tmp.push_back(ans[i - 2][j - 1] + ans[i - 2][j]);
            }
        }
        ans.push_back(tmp);
    }
    return ans;
}

int main() {
    for (auto& i : generate(5)) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
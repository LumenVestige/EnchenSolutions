//
// Created by sanenchen on 25-8-13.
//
#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows) {
    // 特判
    if (numRows == 1)
        return s;
    // 思路：当我的游标在第一行的时候，我就要往下走
    // 当我的游标在最后一行的时候，我要往右上角走
    // 如果我的游标的上面一个没有数据(#代替) 我要往右上角走 否则往下走
    vector<vector<char>> str_vec = vector<vector<char>>(numRows, vector<char>(s.size(), '#'));
    int i = 0, j = 0; // i 是行 j 是列
    for (auto& c : s) {
        str_vec[i][j] = c; // 先把当前的数放进来
        // 游标行走
        if (i == 0) { // 向下走
            i++;
            continue;
        }
        if (i == numRows - 1 || str_vec[i - 1][j] == '#') { // 右上角走
            i--;
            j++;
            continue;
        }
        // 往下走
        i++;
    }
    string ans = "";
    for (auto& i_v : str_vec) {
        for (const auto j_v : i_v) {
            if (j_v != '#') {
                ans += j_v;
            }
        }
    }
    return ans;
}

int main() {
    cout << convert("AB", 1);
    return 0;

}
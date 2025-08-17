//
// Created by sanenchen on 25-8-17.
//
#include <bits/stdc++.h>
using namespace std;

int numberOfPoints(vector<vector<int> > &nums) {
    vector<int> diff(102);
    for (auto& it : nums) {
        diff[it[0]] ++;
        diff[it[1] + 1] --;
    }
    // 还原数组
    for (int i = 1; i < 102; ++i) {
        diff[i] = diff[i - 1] + diff[i];
    }
    int ans = 0;
    for (auto& i : diff) {
        if (i >= 1)
            ans++;
    }

    return ans;
}

int main() {
    vector<vector<int> > nums = {
        {3, 6}, {1, 5}, {4, 7}
    };
    cout << numberOfPoints(nums);
    return 0;
}

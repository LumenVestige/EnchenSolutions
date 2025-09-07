//
// Created by sanenchen on 25-8-17.
//
#include <bits/stdc++.h>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> miles(1100, 0), diff(1100, 0);
    for (auto& it : trips) {
        diff[it[1]] += it[0];
        diff[it[2]] -= it[0];
    }
    // 还原到 miles 上
    // 也就是对diff求一遍前缀和
    miles[0] = diff[0];
    for (int i = 1; i < diff.size(); ++i) {
        miles[i] = miles[i - 1] + diff[i];
    }
    // 遍历miles 看看有没有超出 capacity
    for (auto& it : miles) {
        if (it > capacity)
            return false;
    }
    return true;
}

int main() {
    vector<vector<int>> nums = {
        {2, 1, 5},
        {3, 5, 7}
    };
    cout << carPooling(nums, 3);
    return 0;
}

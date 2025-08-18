//
// Created by sanenchen on 25-8-17.
//
#include <bits/stdc++.h>
using namespace std;
int minGroups(vector<vector<int> > &intervals) {
    map<int, int> diff;
    for (auto& i : intervals) {
        diff[i[0]] += 1;
        diff[i[1] + 1] -= 1;
    }
    // 还原
    int max_ans = 0, sum = 0;
    for (auto& it : diff) {
        max_ans = max(max_ans, sum += it.second);
    }
    return max_ans;
}

int main() {
    vector<vector<int> > intervals = {
        {870474,950951}
    };
    cout << minGroups(intervals);
    return 0;
}

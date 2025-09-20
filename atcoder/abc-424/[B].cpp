//
// Created by sanenchen on 25-9-20.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, int> cnt; // 第 x 个人 完成了 x 个题目
    vector<int> ans;
    while (k--) {
        int t, z;
        cin >> t >> z;
        cnt[t]++;
        if (cnt[t] == m) ans.push_back(t);
    }
    for (auto& i : ans)
        cout << i << " ";
    return 0;
}
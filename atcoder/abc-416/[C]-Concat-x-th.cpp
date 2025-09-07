//
// Created by sanenchen on 25-7-26.
//
#include <bits/stdc++.h>

using namespace std;
vector<string> strs;
int n, k, x;
vector<string> solve(int n) {
    if (n == 0) {
        return {};
    }
    if (n == 1) {
        return strs;
    }
    vector<string> temp_ret;
    auto temp = solve(n - 1);
    for (auto j : strs) {
        for (auto it : temp) {
            temp_ret.push_back(j + it);
        }
    }
    return temp_ret;
}
int main() {
    cin >> n >> k >> x;
    strs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    auto ans = solve(k);
    sort(ans.begin(), ans.end());
    cout << ans[x - 1];


    return 0;
}
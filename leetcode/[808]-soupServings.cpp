//
// Created by sanenchen on 25-8-8.
//
#include <bits/stdc++.h>

using namespace std;

double soupServings(int n) {

    map<pair<int, int>, double> memo;
    function<double(int, int)> dfs = [&](int a, int b) -> double {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1;
        if (b <= 0)
            return 0;
        if (memo.find({a, b}) != memo.end()) {
            return memo[{a, b}];
        }
        double res = (dfs(a - 100, b) + dfs(a - 75, b - 25) + dfs(a - 50, b - 50) + dfs(a - 25, b - 75)) / 4;
        memo[{a, b}] = res;
        return res;
    };

    return dfs(n, n);
}

signed main() {
    cout << soupServings(50);
    return 0;
}

//
// Created by sanenchen on 25-7-25.
//
// https://codeforces.com/problemset/problem/1446/A
// 贪心背包，只需要满足重量大于 w/2即可
#include <bits/stdc++.h>
using namespace std;

vector<long long> knapsack(vector<long long> &things, long long w) {
    long long target = ceil(double(w) / 2);
    long long temp = 0;
    vector<long long> ans;
    for (long long i = 0; i < things.size(); i++) {
        if (things[i] > w - temp)
            continue;
        temp += things[i];
        ans.push_back(i + 1);
        if (temp >= target)
            break;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long m, w;
        cin >> m >> w;
        vector<long long> things(m);
        for (long long j = 0; j < m; j++) {
            cin >> things[j];
        }
        // cout << knapsack(things, w);
        auto temp = knapsack(things, w);
        if (temp.empty())
            cout << "-1";
        else {
            cout << temp.size() << endl;
        }
        for (const auto i1: temp) {
            cout << i1 << " ";
        }
        cout << endl;
    }
    return 0;
}

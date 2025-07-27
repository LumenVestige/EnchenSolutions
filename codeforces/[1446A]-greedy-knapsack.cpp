//
// Created by sanenchen on 25-7-25.
//
// https://codeforces.com/problemset/problem/1446/A
// 贪心背包，只需要满足重量大于 w/2即可
#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> knapsack(vector<unsigned long long> &things, unsigned long long w) {
    vector<pair<unsigned long long, unsigned long long> > newThings;
    newThings.reserve(things.size());
    for (unsigned long long i = 0; i < things.size(); i++) {
        newThings.emplace_back(things[i], i);
    }

    sort(newThings.begin(), newThings.end());
    reverse(newThings.begin(), newThings.end());

    unsigned long long target = (w + 1) / 2;
    unsigned long long temp = 0;
    vector<unsigned long long> ans;
    for (unsigned long long i = 0; i < things.size(); i++) {
        if (newThings[i].first > w - temp)
            continue;
        temp += newThings[i].first;
        ans.push_back(newThings[i].second + 1);
        if (temp >= target)
            break;
    }
    return ans;
}

int main() {
    unsigned long long n;
    cin >> n;
    for (unsigned long long i = 0; i < n; i++) {
        unsigned long long m, w;
        cin >> m >> w;
        vector<unsigned long long> things(m);
        for (unsigned long long j = 0; j < m; j++) {
            cin >> things[j];
        }
        // cout << knapsack(things, w);
        auto temp = knapsack(things, w);
        sort(temp.begin(), temp.end());
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

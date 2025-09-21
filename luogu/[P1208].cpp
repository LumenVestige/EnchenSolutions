//
// Created by sanenchen on 25-9-21.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> farmer(m);
    for (int i = 0; i < m; ++i)
        cin >> farmer[i].first >> farmer[i].second;
    sort(farmer.begin(), farmer.end(), [](const pair<int, int> a, const pair<int, int> b) {
        // 把单价升序排列
        return a.first < b.first;
    });
    int p = 0, ans = 0;
    while (n > 0 && p < farmer.size()) {
        if (farmer[p].second <= n) {
            ans += farmer[p].second * farmer[p].first;
            n -= farmer[p].second;
        } else {
            ans += farmer[p].first * n;
            n = 0;
        }
        p++;
    }
    cout << ans;
    return 0;
}
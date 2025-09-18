//
// Created by sanenchen on 25-9-18.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; // t 是背包容量
    cin >> n >> t;
    vector<pair<int, int> > coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i].first >> coins[i].second;
    // 排序 按照单位价值排序
    sort(coins.begin(), coins.end(), [](const pair<int, int> a, const pair<int, int> b) {
        return (1.0 * a.second / a.first) > (1.0 * b.second / b.first);
    });
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (t >= coins[i].first) {
            ans += coins[i].second;
            t -= coins[i].first;
        } else {
            ans += (1.0 * coins[i].second / coins[i].first) * t;
            break;
        }
    }
    printf("%.2f", ans);
    return 0;
}

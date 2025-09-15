//
// Created by sanenchen on 25-9-14.
//
#include <bits/stdc++.h>
using namespace std;

int miles(int x1, int y1, int x2, int y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main() {
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<pair<int, int>> points(t);
    for (int i = 0; i < t; ++i)
        cin >> points[i].first >> points[i].second;
    // 两层for
    int ans = 0;
    for (int i = 0; i < t - 1; ++i) {
        for (int j = i; j < t; ++j) {
            if (miles(points[i].first,points[i].second,points[j].first,points[j].second) == 1) ans++;
        }
    }
    cout << ans;
    return 0;
}
//
// Created by sanenchen on 25-9-18.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<pair<int, int> > times(n); // 第一个是下标 第二个是打水时间
    for (int i = 0; i < n; ++i) {
        times[i].first = i + 1;
        cin >> times[i].second;
    }
    sort(times.begin(), times.end(), [](const pair<int, int> a, const pair<int, int> b) {
        // 尽量是让打水的快的在前面
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });
    for (auto& i : times) {
        cout << i.first << " ";
    }
    cout << endl;
    // 计算一下等待时间
    int waitTime = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        waitTime += sum;
        sum += times[i].second;
    }
    printf("%.2f", 1.0 * waitTime / n);
    return 0;
}

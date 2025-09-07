//
// Created by sanenchen on 25-7-29.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> areas(n);
        for (int i = 0; i < n; i++) {
            cin >> areas[i];
        }
        // 扫一遍 看看是否全等
        int tmp = 1;
        for (int i = 1; i < n; i++) {
            if (areas[i] == areas[i - 1])
                tmp++;
        }
        if (tmp == n) {
            cout << "NO" << endl;
            continue;
        }
        vector<pair<int, int>> ans;
        // 如果与第一个不同，那么就连在第一个上
        // 否则连在与第一个不同的上面
        // 先找到与第一个不同的数
        for (int i = 1; i < n; i++) {
            if (areas[i] != areas[0]) {
                tmp = i;
                break;
            }
        }
        // 遍历
        for (int i = 1; i < n; i++) {
            if (areas[i] != areas[0]) {
                ans.emplace_back(1, i + 1);
            } else {
                ans.emplace_back(tmp + 1, i + 1);
            }
        }
        cout << "YES" << endl;
        for (auto& it : ans) {
            cout << it.first << " " << it.second << endl;
        }
    }

    return 0;
}
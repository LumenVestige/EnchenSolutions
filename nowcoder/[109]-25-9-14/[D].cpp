//
// Created by sanenchen on 25-9-14.
//
#include <bits/stdc++.h>
using namespace std;
// 未解决
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<map<int, int> > points(t);
    map<map<int, int>, bool> pointExist;
    map<int, vector<pair<int, int> > > pointX;
    map<int, vector<pair<int, int> > > pointY;
    for (int i = 0; i < t; i++) {
        cin >> points[i][0] >> points[i][1];
        pointExist[{points[i][0], points[i][1]}] = true;
        pointX[points[i][0]].push_back({points[i][0], points[i][1]});
        pointY[points[i][1]].push_back({points[i][0], points[i][2]});
    }
    int ans = 0;
    // 遍历每一个点 去找他的好矩形 在 左上 右上 右下 左下 是否存在
    for (auto &it: points) {
        // 扫描自己这一列
        for (auto& h : pointX[it[0]]) {
            // 判断是否高为1
            if (abs(h.second - it[1]) == 1) {
                // 横向扫描这一行
                for (auto& r : pointY[it[1]]) {
                    if (pointExist[{r.first, it[1]}]) ans++;
                }
            }
        }

        for (auto &it: points) {
            // 扫描自己这一行
            for (auto& r : pointY[it[1]]) {
                // 判断是否宽为1
                if (abs(r.first - it[0]) == 1) {
                    // 横向扫描这一行
                    for (auto& h : pointX[it[0]]) {
                        //if (pointExist[it[0]] == h.second) ans++;
                    }
                }
            }

        }
    }
    cout << ans;
    return 0;
}

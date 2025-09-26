#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, t;
    cin >> n >> t;
    vector<int> active(n), upper(n);
    int allActive = 0;
    for (int i = 0; i < n; ++i) {
        cin >> active[i];
        allActive += active[i];
    }
    if (allActive >= t) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; ++i) 
        cin >> upper[i];
    // 当然就是 活跃值越高 越好 可复制次数越高越好
    // 构建一个pair
    vector<pair<int,int>> data;// 第一个是代表着玩家活跃度，第二个是玩家的可复制次数
    // 当然是活跃度优先了
    for (int i = 0; i < n; ++i) {
        data.emplace_back(active[i], upper[i]);
    }
    sort(data.begin(), data.end(), [](const pair<int,int> a, const pair<int,int> b){
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    });
    int needActive = t - allActive;
    int ans = 0;
    int point = 0;
    while (needActive > 0) {
        // 截止判断
        if (point == data.size()) {
            cout << -1;
            return 0;
        }
        // 取出第一个
        // 判断是否第一个可以全部加上去
        if (data[point].first * data[point].second <= needActive) {
            ans += data[point].second;
            needActive -= data[point].first * data[point].second;
            point++;
        } else {
            // 否则就是部分的 并且跳出循环了
            int needAdd = ceil(1.0 * needActive / data[point].first);
            ans += needAdd;
            needActive -= needAdd * data[point].first;
        }
    }
    // 说明等于0 或者小于0 结束了
    cout << ans;
    return 0;
}
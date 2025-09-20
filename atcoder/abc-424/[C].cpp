//
// Created by sanenchen on 25-9-20.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    unordered_map<int, bool> skills;
    unordered_map<int, vector<int>> cnt;// 依赖关系 会了 xxx 后 可以会 xxx
    int ans = 0;
    vector<pair<int, int>> inputs(n + 1);
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        inputs[i] = {a, b};
    }
    for (int i = 1; i <= n; ++i) {
        cnt[inputs[i].first].push_back(i);
        cnt[inputs[i].second].push_back(i);
    }
    // 从 0 开始 如果还没学 那么入队
    queue<int> q;
    q.push(0); // 如果会了x 那么就入队 看看还能学什么
    while (!q.empty()) {
        int t = q.front();
        vector<int> v = cnt[t];
        for (auto& i : v) {
            // 看看是不是已经学会了
            if (!skills[i]) {
                skills[i] = true;
                ans++;
                q.push(i);
            }
        }
        q.pop();
    }
    cout << ans;
    return 0;
}
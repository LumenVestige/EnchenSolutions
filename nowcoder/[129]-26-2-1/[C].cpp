#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grids(n, vector<int>(m));
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grids[i][j];
            if (grids[i][j] != 0) {
                pq.push(grids[i][j]);
            }
        }
    }
    int cnt = 0, score = 0;
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        if (!pq.empty() && pq.top() == top) {
            if (top+1 >= k) {
                score++;
            }
            pq.push(top+1);
            pq.pop();
            cnt++;
        }
    }
    cout << cnt << " " << score;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<int> boundaries;
    // 这个地方要用事件驱动，而不是从头遍历到右
    for (auto& b : buildings) {
        boundaries.push_back(b[0]);
        boundaries.push_back(b[1]);
    }
    sort(boundaries.begin(), boundaries.end());
    boundaries.erase(unique(boundaries.begin(), boundaries.end()), boundaries.end());
    int cur = 0;
    int n = buildings.size();
    priority_queue<pair<int, int>> pq; 
    vector<vector<int>> ans;
    int last = 0;
    int rightMax = 0;
    for (auto& i : buildings) {
        rightMax = max(rightMax, i[1]);
    }
    for (auto& i : boundaries) {
        // cout << i;
        while (cur < n && buildings[cur][0] == i) {
            pq.push({buildings[cur][2], buildings[cur][1]});
            cur++;
        }
        // 把最高的 并且有效的塞进去
        while (!pq.empty()) {
            if (pq.top().second <= i) {
                pq.pop();
                continue;
            }
            if (pq.top().first != last) {
                ans.push_back({i, pq.top().first});
                last = pq.top().first;
                // cout << 1;
            }
            break;
        }
        if (pq.empty() && last != 0) {
            ans.push_back({i, 0});
            last = 0;
        }
        // cout << endl;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n;
    cin >> n;
    unordered_map<int, unordered_set<char>> cnt;
    unordered_map<int, int[2]> tmp;
    vector<vector<int>> ans;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        char color;
        cin >> num >> color;
        if (!cnt[num].count(color)) {
            cnt[num].insert(color);
            if (tmp[num][0] == 0) {
                tmp[num][0] = i + 1;
            } else if (tmp[num][1] == 0) {
                tmp[num][1] = i + 1;
                ans.push_back({tmp[num][0], tmp[num][1]});
                tmp[num][0] = 0;
                tmp[num][1] = 0;
                count += 2;
            }
        }
    }
    cout << count << endl;
    for (auto& it : ans) {
        cout << it[0] << " " << it[1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<pair<string, int>> data;
    // 记录sensei位置 能力
    int sensei = 0;
    for (int i = 0; i < n; ++i) {
        string name;
        int power;
        cin >> name >> power;
        if (name == "sensei") {
            sensei = power;
        }
        data.emplace_back(name, power);
    }
    // 排序
    sort(data.begin(), data.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    });
    int ans = sensei;
    for (auto [name, power] : data) {
        if(power < sensei) {
            ans += power;
        }
    }
    cout << ans;
    return 0;
}
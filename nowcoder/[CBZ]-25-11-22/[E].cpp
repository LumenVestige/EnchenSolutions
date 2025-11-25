#include <bits/stdc++.h>
using namespace std;
#define int long long

struct med {
    int taugh, work;
};
bool cmp(const med& a, const med& b) {
    if (a.taugh != b.taugh) {
        return a.taugh < b.taugh;
    }
    return a.work > b.work;
}
signed main() {
    int n;
    cin >> n;
    vector<med> ms(n);
    for (int i = 0; i < n; ++i) {
        cin >> ms[i].taugh >> ms[i].work;
    }
    // 自定义排序
    sort(ms.begin(), ms.end(), cmp);
    cout << 1;
    return 0;
}
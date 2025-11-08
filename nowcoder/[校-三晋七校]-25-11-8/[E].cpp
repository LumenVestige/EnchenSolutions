#include <bits/stdc++.h>
using namespace std;
#define int long long
struct mem {
    int ques;
    int time;
    bool target = false;
};
bool cmp(const mem& a, const mem& b) {
    if (a.ques != b.ques) {
        return a.ques > b.ques;
    }
    return a.time < b.time;
}

signed main() {
    vector<mem> vecs;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int q, t;
        cin >> q >> t;
        vecs.push_back({q, t, i == 0});
    }
    sort(vecs.begin(), vecs.end(), cmp);
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (vecs[i].target) {
            pos = i + 1;
            break;
        }
    }
    if (pos <= n * 0.1) {
        cout << "gold";
    } else if (pos <= n * 0.3) {
        cout << "silver";
    } else if (pos <= n * 0.6) {
        cout << "bronze";
    } else {
        cout << "iron";
    }
    return 0;
}
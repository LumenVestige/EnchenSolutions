#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    deque<int> deq;
    bool headFlag = false;
    for (int x = 0; x < n; ++x) {
        char i = str[x];
        if (i == 'o') {
            
            if (!headFlag) {
                deq.push_back(x);
            } else {
                deq.push_front(x);
            }
            headFlag = !headFlag;
        } else {
            if (!headFlag) {
                deq.push_back(x);
            } else {
                deq.push_front(x);
            }
        }

        // for (auto& i : deq) {
        //     cout << i+1 << " ";
        // }
        // cout << endl;
    }
    if (headFlag == 1) {
        reverse(deq.begin(), deq.end());
    }
    for (auto& i : deq) {
        cout << i+1 << " ";
    }
    // cout << headFlag;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
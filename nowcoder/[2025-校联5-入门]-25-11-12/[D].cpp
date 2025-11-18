#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(int c) {
    bool flag = false;
    function<bool(int, int)> dfs = [&](int k, int player) {
        if (k == 0 && player == 0) {
            flag = true;
            return false;
        } else if (k == 0 && player == 1) {
            return true;
        }
        // 对于 player = 1 必须每一个都是true 否则就返回false
        if (player == 1) {
            for (int i = 1; i <= k; ++i) {
                if (dfs(k - i, 0) == false) {
                    return false;
                }
            }
            return true;
        } else {
            // 对于 player = 0 只要有一个等于true 就可以通行
            for (int i = 1; i <= k; ++i) {
                if (dfs(k - i, 1)) {
                    return true;
                }
            }
            return false;
        }
    };
    for (int i = 1; i <= 1; ++i) {
        if (dfs(c - i, 1)) {
            cout << "Bob" << endl;
            return;
        }
    }
    cout << "Alice" << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    solve(5);
    // for (int i = 2; i < 1000; ++i) {
    //     cout << i << ": ";
    //     solve(i);
    // }
    return 0;
}
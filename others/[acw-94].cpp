//
// Created by sanenchen on 25-7-28.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> state(n, 0); // 状态 判断当前是选了 还是没选 选了是 1 没选是2 默认是0
    function<void(int)> dfs = [&](int c) -> void {
        if (c == n) {
            for (int i = 0; i < n; i++) {
                if (state[i] == 1) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
            return;
        }

        // 不选
        state[c] = 2;
        dfs(c + 1);
        state[c] = 0;

        // 选
        state[c] = 1;
        dfs(c + 1);
        state[c] = 0;
    };

    dfs(0);
    return 0;
}

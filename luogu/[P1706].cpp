//
// Created by sanenchen on 25-7-28.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> state(n), tar(n);
    function<void(int)> dfs = [&](int x) -> void {
        if (x == n) {
            for (int i = 0; i < n; i++) {
                printf("%5d", tar[i]);
            }
            cout << endl;
            return;
        }
        // 如果 小于了n 那么dfs继续搞起来
        for (int i = 0; i < n; i++) {
            if (!state[i]) {
                state[i] = 1;
                tar[x] = i + 1;
                dfs(x + 1);
                state[i] = 0;
            }
        }
    };
    dfs(0);
    return 0;
}
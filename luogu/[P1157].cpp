//
// Created by sanenchen on 25-7-28.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >>n >> k;
    vector<int> state(n);
    function<void(int)> dfs = [&](int x) -> void {
        if (x == n) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (state[i] == 1) {
                    temp.push_back(i + 1);
                }
            }
            if (temp.size() == k) {
                for (auto& it : temp) {
                    cout << setw(3) << it;
                }
                cout << endl;
            }
            return;
        }
        // 选
        state[x] = 1;
        dfs(x + 1);
        state[x] = 0;
        // 不选
        state[x] = 2;
        dfs(x + 1);
        state[x] = 0;
    };
    dfs(0);
    return 0;
}
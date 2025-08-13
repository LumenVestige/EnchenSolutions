//
// Created by sanenchen on 25-8-10.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> o_nums(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> o_nums[i];
    }
    // dfs
    vector<int> memo(2 * n, 0); // 0 未使用 1 已经使用
    vector<pair<vector<int>, vector<int>>> pre_n;
    // dfs
    function<void(int, int)> dfs = [&](int x, int c) -> void {
        if (x == n) {
            vector<int> tmp;
            vector<int> tmp_o = o_nums;
            for (int i = 0; i < memo.size(); ++i) {
                if (memo[i] == 1) {
                    tmp.push_back(o_nums[i]);
                    tmp_o.erase(tmp_o.begin() + i);
                }
            }
            if (tmp.size() == n) {
                for (auto& i : tmp) {
                    cout << i << " ";
                }
                cout <<endl << "Next" << endl;
                for (auto& i : tmp_o) {
                    cout << i << " ";
                }

                cout << endl;
            }
            return;
        }
        for (int i = c; i < o_nums.size(); ++i) {
            // 选
            memo[i] = 1;
            dfs(x + 1, c + 1);
            memo[i] = 0;
            // 不选
            dfs(x + 1, c + 1);
        }

    };

    dfs(0, 0);
    return 0;
}
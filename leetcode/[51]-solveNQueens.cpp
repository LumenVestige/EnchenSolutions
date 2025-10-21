#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> state(n, string(n, '.'));
    vector<bool> row(n, false);
    vector<bool> mainLine(2 * n, false);
    vector<bool> subLine(2 * n, false);
    function<void(int)> dfs = [&](int x) {
        if (x == n) {
            ans.push_back(state);
            return ;
        }

        // 下一轮
        for (int i = 0; i < n; ++i) {
            if (row[i] || mainLine[x - i + n - 1] || subLine[x + i]) {
                continue;
            }
            state[x][i] = 'Q';
            row[i] = true;
            mainLine[x - i + n - 1] = true;
            subLine[x + i] = true;
            dfs(x + 1);
            state[x][i] = '.';
            row[i] = false;
            mainLine[x - i + n - 1] = false;
            subLine[x + i] = false;
        }
    };
    dfs(0);
    return ans;
}

int main() {
    for (auto& i : solveNQueens(4)) {
        for (auto& j : i) {
            cout << j << endl;
        }
        cout << endl;
    }
    return 0;
}
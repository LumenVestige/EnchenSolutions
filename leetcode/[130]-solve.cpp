//
// Created by sanenchen on 25-9-30.
//
#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<char>>& board) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> cnt(board.size(), vector<int>(board[0].size(), 0));
    vector<pair<int, int>> needChange;
    function<bool(int , int)> dfs = [&](int x, int y)-> bool {
        // 标记当前
        cnt[x][y] = 1;
        // 记录当前
        needChange.emplace_back(x, y);
        bool canGo = false;
        if (x == 0 || y == 0 || x == board.size() - 1 || y == board[0].size() - 1)
            canGo = true;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && cnt[i][j] == 0 && board[i][j] == 'O') {
                auto tmp = dfs(i, j);
                if (tmp) canGo = true;
            }
        }
        return canGo;
    };
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (cnt[i][j] == 0 && board[i][j] == 'O') {
                if (const bool res = dfs(i, j); !res) {
                    for (auto& [x, y] : needChange) {
                        board[x][y] = 'X';
                    }
                }
                needChange.clear();
            }
        }
    }
}
int main() {
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(board);
    for (auto& i : board) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
//
// Created by sanenchen on 25-10-2.
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
    vector<vector<char>> nearBoom(board.size(), vector<char>(board[0].size(), '0'));
    int DIRS_ALL[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    // 统计附近的雷
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            for (auto &[mx, my] : DIRS_ALL) {
                int x = mx + i, y = my + j;
                if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'M')
                    nearBoom[i][j]++;
            }
        }
    }

    function<void(int, int)> dfs = [&](int x, int y) -> void {
        // cnt[x][y] = 1;
        // 如果拓展到数字，则退出了
        if (nearBoom[x][y] != '0') {
            board[x][y] = nearBoom[x][y];
            return;
        }
        board[x][y] = 'B';
        for (auto &[mx, my] : DIRS_ALL) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'E') {
                dfs(i, j);
            }
        }
    };
    if (board[click[0]][click[1]] == 'M')
        board[click[0]][click[1]] = 'X';
    else
        dfs(click[0], click[1]);
    return board;
}

int main() {
    vector<vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'M', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {3, 0};
    for (auto &i : updateBoard(board, click)) {
        for (auto &j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
public:
    UnionFind(int x, int y, vector<vector<char>> c) {
        parent = vector<int>(x * y + 1);
        parent[x * y] = x * y;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if ((i == 0 || j == 0 || i == x - 1 || j == y - 1) && c[i][j] == 'O') {
                    parent[i * y + j] = parent[x * y];
                    continue;
                }
                parent[i * y + j] = i * y + j;
            }
        }
    }

    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return; 
        }
        parent[rootX] = rootY;
    }

    bool connected(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        return rootX == rootY;
    }
};

void solve(vector<vector<char>>& board) {
    auto uf = UnionFind(board.size(), board[0].size(), board);
    const int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == 'O') {
                // 他的上下左右都联系到祖师爷上
                for (auto& [mx, my] : DIRS) {
                    int x = mx + i, y = my + j;
                    if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == 'O') {
                        uf.union_(x * board[0].size() + y, i * board[0].size() + j);
                    }
                }
            }
        }
    }
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (!uf.connected(i * board[0].size() + j, board.size() * board[0].size())) { 
                // 询问和祖师爷有没有关系
                board[i][j] = 'X';
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
#include <bits/stdc++.h>
using namespace std;

int maxPathScore(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    // dp[x][y][cost] = 最大分数
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(k+1, -1))
    );
    dp[0][0][0] = 0; // 起点，花费0分数0
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int c = 0; c <= k; c++) {
                if (dp[x][y][c] == -1) continue;
                int sc = dp[x][y][c];
                int cost = c;
                if (grid[x][y] == 1) {
                    sc++;
                    cost++;
                } else if (grid[x][y] == 2) {
                    sc += 2;
                    cost++;
                }
                if (cost > k) continue;
                // 向右
                if (y + 1 < m) {
                    int nc = c + 1;
                    if (nc <= k) {
                        int nsc = dp[x][y][c] + (grid[x][y+1] == 1 ? 1 : grid[x][y+1] == 2 ? 2 : 0);
                        dp[x][y+1][nc] = max(dp[x][y+1][nc], nsc);
                    }
                }
                if (x + 1 < n) {
                    int nc = c + 1;
                    if (nc <= k) {
                        int nsc = dp[x][y][c] + (grid[x+1][y] == 1 ? 1 : grid[x+1][y] == 2 ? 2 : 0);
                        dp[x+1][y][nc] = max(dp[x+1][y][nc], nsc);
                    }
                }
            }
        }
    }

    int score = -1;
    for (int c = 0; c <= k; c++) {
        score = max(score, dp[n-1][m-1][c]);
    }
    return score;
}

int main() {
    vector<vector<int>> grid = {{0, 2, 2}, {1, 1, 1}, {0, 0, 2}};
    cout << maxPathScore(grid, 3);
    return 0;
}

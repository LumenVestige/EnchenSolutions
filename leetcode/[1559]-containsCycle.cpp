#include <bits/stdc++.h>
using namespace std;
// class UnionFind {
// public:
//     vector<int> parent;
//     UnionFind(int x) {
//         parent.resize(x);
//         for (int i = 0; i < x; ++i) {
//             parent[i] = i;
//         }
//     }

//     int find(int x) {
//         while (x != parent[x]) {
//             parent[x] = parent[parent[x]];
//             x = parent[x];
//         }
//         return x;
//     }

//     void merge(int x, int y) {
//         int rootX = find(x);
//         int rootY = find(y);
//         // A 挂在 B上
//         parent[rootX] = parent[rootY];
//     }

//     bool same(int x, int y) {
//         return find(x) == find(y);
//     }
// };

// bool containsCycle(vector<vector<char>>& grid) {
//     vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
//     int DIRS[2][2] = {{0, 1}, {1, 0}};
//     int m = grid.size(), n = grid[0].size();
//     UnionFind uf(m * n);
//     for (int i = 0; i < grid.size(); ++i) {
//         for (int j = 0; j < grid[0].size(); ++j) {
//             for (auto& [mx, my] : DIRS) {
//                 int a = mx + i;
//                 int b = my + j;
//                 if (a < m && b < n && grid[a][b] == grid[i][j]) {
//                     if (uf.same(i * n + j, a * n + b)) {
//                         return true;
//                     }
//                     uf.merge(i * n + j, a * n + b);
//                 }
//             }
//         }
//     }
    
//     return false;
// }

bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    auto dfs = [&](auto&& dfs, int x, int y, int i, int j) {
        vis[x][y] = 1;
        for (auto& [mx, my] : DIRS) {
            int a = mx + x;
            int b = my + y;
            if (a < 0 || b < 0 || a >= m || b >= n) {
                continue;
            }
            if (a == i && b == j) {
                continue;
            }
            if (grid[a][b] != grid[x][y]) {
                continue;
            }
            if (vis[a][b]) {
                return true;
            }
            if (dfs(dfs, a, b, x, y)) return true;
        }
        return false;
    };
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                if (dfs(dfs, i, j, -1, -1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> grid = {{'c', 'a', 'd'}, {'a', 'a', 'a'}, {'a', 'a', 'd'}, {'a', 'c', 'd'}, {'a', 'b', 'c'}};
    cout << containsCycle(grid) << endl;
    return 0;
}
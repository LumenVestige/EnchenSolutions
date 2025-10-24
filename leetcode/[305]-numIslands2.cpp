#include <bits/stdc++.h>
using namespace std;

struct Dsu {
    unordered_map<int, int> parent;
    int size = 0;
    Dsu() {}
    int find(int x) {
        if (!parent.count(x)) {
            parent[x] = x;
            size++;
        }
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool merge(int x, int y) {
        if (!parent.count(x)) {
            parent[x] = x;
            size++;
        }
        if (!parent.count(y)) {
            parent[y] = y;
            size++;
        }
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        parent[rootY] = rootX;
        size--;
        return true;
    }
};

vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    // 初始化grid
    vector<vector<int>> grid = vector<vector<int>>(m ,vector<int>(n, 0));
    vector<int> ans;
    Dsu dsu = Dsu();
    unordered_map<int, int> locaToIndex; // 第一个是坐标地址 第二个是对应的下标
    for (int i = 0; i < positions.size(); ++i) {
        int x = positions[i][0], y = positions[i][1];
        locaToIndex[x * n + y] = i;
    }
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int i = 0; i < positions.size(); ++i) {
        int x = positions[i][0], y = positions[i][1];
        dsu.find(x * n + y);
        for (auto& [mx, my] : DIRS) {
            int a = mx + x, b = my + y;
            if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b]) {
                dsu.merge(x * n + y, a * n + b);
            }
        }
        if (grid[x][y]) {
            ans.push_back(ans.back());
            continue;
        }
        grid[x][y] = 1;
        ans.push_back(dsu.size);
    }
    return ans;
}
int main() {
    vector<vector<int>> posotions = {
    {0, 0},
    {0, 1},
    {1, 2},
    {2, 1},
    {1, 0},
    {0, 0},
    {2, 2},
    {1, 2},
    {1, 1},
    {0, 1}
};
    for (auto& i : numIslands2(3, 3, posotions)) {
        cout << i << " ";
    }
    return 0;
}
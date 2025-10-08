//
// Created by sanenchen on 25-10-2.
//
#include <bits/stdc++.h>
using namespace std;

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    q.emplace(entrance[0], entrance[1]);
    maze[entrance[0]][entrance[1]] = '+';
    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            // 修改当前为墙
            int x = q.front().first, y = q.front().second;
            q.pop();

            cout << x << y << endl;
            // 扫描到边界
            if (x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1) {
                if (steps != 0)
                    return steps;
            }
            for (auto &[mx, my] : DIRS) {
                int i = mx + x, j = my + y;
                if (i >= 0 && i < maze.size() && j >= 0 && j < maze[0].size() && maze[i][j] == '.') {
                    q.emplace(i, j);
                    maze[i][j] = '+';
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    vector<vector<char>> maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};
    cout << nearestExit(maze, entrance);
    return 0;
}
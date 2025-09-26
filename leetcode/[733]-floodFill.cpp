#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // 构建一张标记画像 0 代表尚未遍历 1代表已经遍历
    vector<vector<int>> alreadyCnt(image.size(), vector<int>(image[0].size(), 0));
    int originColor = image[sr][sc];
    int DIRS[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    function<void(int, int)> dfs = [&](int x, int y) {
        // 标记当前的模块为1
        alreadyCnt[x][y] = 1;
        // 修改当前的颜色
        image[x][y] = color;
        for (auto& [mx, my] : DIRS) {
            int i = mx + x, j = my + y;
            if (i >= 0 && i < image.size() && j >= 0 && j < image[0].size() && alreadyCnt[i][j] == 0 && image[i][j] == originColor) {
                dfs(i, j);
            }
        }
    };
    dfs(sr,sc);
    return image;
}
int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    for(auto i : floodFill(image, 1, 1, 2)) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
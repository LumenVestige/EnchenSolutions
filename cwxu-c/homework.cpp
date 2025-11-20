#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grids(n + 1, vector<int>(n + 1, 999)); 
    int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 下0 上1 右2 左3
    int direction = 2; 
    int i = 1, j = 1; 
    int num = 1;
    grids[i][j] = num++;
    while (num <= n * n) {
        int ni = i + DIRS[direction][0];
        int nj = j + DIRS[direction][1];
        if (ni >= 1 && ni <= n && nj >= 1 && nj <= n && grids[ni][nj] == 999) {
            i = ni;
            j = nj;
            grids[i][j] = num++;
        } else {
            if (direction == 2) direction = 0;
            else if (direction == 0) direction = 3;
            else if (direction == 3) direction = 1;
            else if (direction == 1) direction = 2;
        }
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            printf("%3d", grids[x][y]);
        }
        printf("\n");
    }
    
    return 0;
}
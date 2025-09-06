//
// Created by sanenchen on 25-8-19.
//
#include <bits/stdc++.h>
using namespace std;

class Prefix2D {
private:
    vector<vector<int> > prefix;

public:
    Prefix2D(vector<vector<int> > &nums) {
        // 构建二维前缀和数组
        prefix = nums;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j < nums[0].size(); ++j) {
                prefix[i][j] = nums[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int query(int x1, int y1, int x2, int y2) {
        // 22 12 21 11
        return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
    }
};

bool isRight(int x1, int y1, int x2, int y2, int target) {
    int needed = pow((y2 - y1 + 1), 2);
    return needed == target;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > nums(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> nums[i][j];
        }
    }
    // 构建二维前缀和
    Prefix2D prefix_2d(nums);
    // 遍历每一个位置，按照对角线来询问
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // i j 为当前位置 e r 为变化位置
            int e = i, r = j;
            while (e <= n && r <= m) {
                if (isRight(i, j, e, r, prefix_2d.query(i, j, e, r)))
                    ans = max(ans, r - j + 1);
                e++, r++;
            }
        }
    }
    cout << ans;
    return 0;
}

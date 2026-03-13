#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    int k = log2(n);
    vector<vector<int>> stMin(n+1, vector<int>(k+1)), stMax(n+1, vector<int>(k+1));
    // 初始化st表
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        stMin[i][0] = nums[i];
        stMax[i][0] = nums[i];
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j + (1 << i) - 1 < n; ++j) {
            stMin[j][i] = min(stMin[j][i-1], stMin[j+(1<<(i-1))][i-1]);
            stMax[j][i] = max(stMax[j][i-1], stMax[j+(1<<(i-1))][i-1]);
        }
    }
    while (q--){
        int c, l, r;
        cin >> c >> l >> r;
        l--, r--;
        int k = log2(r - l + 1);
        int MIN = min(stMin[l][k], stMin[r-(1<<(k))+1][k]);
        int MAX = max(stMax[l][k], stMax[r-(1<<(k))+1][k]);
        if(c==1) {
            cout << MIN << endl;
        } else {
            cout << MAX << endl;
        }
    }
    return 0;
}
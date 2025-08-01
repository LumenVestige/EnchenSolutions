#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;  // 测试案例数量
    while (m--) {
        int n;
        cin >> n;  // 糖果数量
        vector<int> wgt(n);
        int total = 0;  // 总重量
        for (int i = 0; i < n; ++i) {
            cin >> wgt[i];
            total += wgt[i];
        }
        
        // 总重量为奇数，不可能平分
        if (total % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        
        int target = total / 2;  // 目标重量（一半）
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // 基础状态：重量0可以达到
        
        // 0-1背包动态规划
        for (int weight : wgt) {
            // 从后往前遍历，避免重复使用同一个糖果
            for (int j = target; j >= weight; --j) {
                if (dp[j - weight]) {
                    dp[j] = true;
                }
            }
        }
        
        // 输出是否能达到目标重量
        cout << (dp[target] ? "YES\n" : "NO\n");
    }
    return 0;
}

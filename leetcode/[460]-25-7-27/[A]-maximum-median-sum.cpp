//
// Created by sanenchen on 25-7-27.
//
#include "../LeetCodes.h"
#define int long long

long long LeetCodes::maximumMedianSum(vector<signed> &nums) {
    function<vector<int>(vector<signed>)> dfs = [&](vector<signed> parm) -> vector<int> {
        if (parm.empty()) return {0};
        vector<int> temp;
        for (int i = 0; i < parm.size() - 2; i++) {
            for (int j = 0; j < parm.size() - 1; j++) {
                for (int k = 0; k < parm.size(); k++) {
                    // 计算当前中位数，删除当前中位数，继续递归
                    int avg = parm[j];
                    auto t = parm;
                    t.erase(t.begin() - 1 + i);
                    t.erase(t.begin() - 1 - 1 + j);
                    t.erase(t.begin() - 1 - 2 + k);
                    auto temp_ret = dfs(t);
                    // 递归返回 加入道到当前结果中
                    for (auto& it : temp_ret) {
                        temp.push_back(avg + it);
                    }
                }
            }
        }
        return temp;
    };
    int ans = 0;
    auto avg = dfs(nums);
    for (auto i : avg) {
        // cout << i << endl;
        ans = max(ans, i);
    }

    return ans - 1;
}

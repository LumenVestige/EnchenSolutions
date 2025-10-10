//
// Created by sanenchen on 25-10-10.
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> permute(vector<int>& nums) {
    // 回溯
    vector<vector<int>> ans;
    vector<bool> mem(nums.size(), false);
    function<void(vector<int>)> dfs = [&](vector<int> cnt) {
        if (cnt.size() == nums.size())
            ans.push_back(cnt);
        for (int i = 0; i < nums.size(); ++i) {
            if (!mem[i]) { // 没有选中
                mem[i] = true;
                cnt.push_back(nums[i]);
                dfs(cnt);
                cnt.pop_back();// 回溯
                mem[i] = false;
            }
        }
    };
    dfs({});
    return ans;
}
int main() {
    vector<int> nums = {1, 2, 3};
    for (auto& i : permute(nums)) {
        for (auto& j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
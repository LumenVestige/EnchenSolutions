//
// Created by sanenchen on 25-7-28.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        cin >> nums[i];
    }
    vector<int> ans;
    function<void(int)> dfs = [&](int x) -> void {
        ans.push_back(x);
        if (x == 1) {
            return;
        }
        dfs(nums[x]);
    };
    dfs(n);
    reverse(ans.begin(), ans.end());
    for (auto& it : ans) {
        cout << it << " ";
    }
}
//
// Created by sanenchen on 25-8-22.
//
#include <bits/stdc++.h>
using namespace std;

// void allCompose(int n) {
//     vector<int> nums(n), memo(n, 0);
//     for (int i = 0; i < n; ++i)
//         nums[i] = i;
//     function<void(int)> dfs = [&](int x) {
//         if (x == nums.size()) {
//             // for (auto& i : nums)
//             //     cout << i << " ";
//             // cout << endl;
//         }
//         for (int i = x; i < nums.size(); ++i) {
//             swap(nums[x], nums[i]);
//             dfs(x + 1);
//             swap(nums[x], nums[i]);
//         }
//     };
//     dfs(0);
// }

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     unordered_map<string, vector<string>> str;
//     for (auto& i : strs) {
//         string tmp = i;
//         sort(i.begin(), i.end());
//         str[i].push_back(tmp);
//     }
//     vector<vector<string>> ans;
//     for (auto& i : str) {
//         ans.push_back(i.second);
//     }
//     return ans;
// }
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> cnt;
    for (auto i : strs) {
        string tmp = i;
        sort(tmp.begin(), tmp.end());
        cnt[tmp].push_back(i);
    }
    vector<vector<string>> ans;
    for (auto& [k, v] : cnt) {
        ans.push_back(v);
    }
    return ans;
}
int main() {
    //allCompose(100);
    return 0;

}

//
// Created by sanenchen on 25-7-27.
//
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(string ans, vector<int> nums) {
    vector<int> temp;
    int left = 0, right = nums.size() - 1;
    for (int i = 0; i < ans.length(); i++) {
        if (ans[i] == 'L') {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right--;
        }
    }

    // 判断 temp 是否符合条件
    // 只要连续5位递减就是错
    int temp_in = 1;
    int temp_de = 1;
    for (int i = 1; i < temp.size(); i++) {
        if (temp[i] > temp[i - 1]) {
            temp_in ++;
            if (temp_in >= 5) {
                return false;
            }
        } else temp_in = 1;
        if (temp[i] < temp[i - 1]) {
            temp_de ++;
            if (temp_de >= 5) {
                return false;
            }
        } else temp_de = 1;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;
        vector<int> nums;
        int counter = n;
        queue<string> q;
        nums.reserve(n);
        while (counter--) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        q.emplace("");
        vector<string> temp_ans;
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            if (current.length() == n) {
                // temp_ans.push_back(current);
                // 判断当前
                if (check(current, nums)) {
                    cout << current << endl;
                    break;
                }
            }
            if (current.length() > n)
                break;
            q.push(current + "L");
            q.push(current + "R");
        }
        // 判断每个备选答案
    }
    return 0;
}

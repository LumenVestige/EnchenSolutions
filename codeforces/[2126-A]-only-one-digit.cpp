//
// Created by sanenchen on 25-7-23.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    vector<int> ans;
    nums.resize(n);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    for (auto i : nums) {
        // 找最小
        int temp = 10;
        while (i != 0) {
            temp = min(temp, i % 10);
            i /= 10;
        }
        ans.push_back(temp);
    }
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}
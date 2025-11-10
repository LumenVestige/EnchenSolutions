//
// Created by sanenchen on 25-7-24.
//
#include <bits/stdc++.h>
using namespace std;

void process(vector<int>& nums) {
    // 贪心：目光短浅
    if (nums[0] < nums[1]) // 2 3交换 稳住最小的那个
        cout << nums[0] + nums[0] << endl;
    else
        cout << nums[0] + nums[1] << endl; // 1 2交换 交换更早一些 ai = ai + aj
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        vector<int> nums;
        nums.resize(n);
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }
        process(nums);
    }
    return 0;
}
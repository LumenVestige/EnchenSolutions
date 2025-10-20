//
// Created by sanenchen on 25-10-20.
//
#include <bits/stdc++.h>
using namespace std;
int find_x(int n, vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == n) {
            return i + 1;
        }
    }
}
int main() {
    vector<int> nums(3);
    int n = 3;
    for (int i = 0; i < 3; ++i) {
        cin >> nums[i];
    }
    cout << find_x(1, nums) << " ";
    cout << find_x(2, nums) << " ";
    cout << find_x(3, nums) << " ";
    return 0;
}
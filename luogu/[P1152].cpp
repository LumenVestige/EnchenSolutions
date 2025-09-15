//
// Created by sanenchen on 25-9-15.
//
// P1152 欢乐的跳
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n), diff(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    for (int i = 1; i < n; ++i)
        diff[i - 1] = abs(nums[i] - nums[i - 1]);
    sort(diff.begin(), diff.end());
    for (int i = 1; i < diff.size(); ++i) {
        if (diff[i] != diff[i - 1] + 1) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}
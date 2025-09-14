//
// Created by sanenchen on 25-9-13.
//
#include <bits/stdc++.h>
using namespace std;

int smallestAbsent(vector<int> &nums) {
    int sum = 0;
    for (auto &i: nums)
        sum += i;
    int avg = sum / (int)nums.size();
    unordered_map<int, int> cnt;
    for (auto &i: nums) {
        cnt[i]++;
    }
    if (avg < 0) {
        avg = 0;
    }
    while (true) {
        if (cnt.find(avg + 1) == cnt.end()) {
            return avg + 1;
        }
        avg++;
    }
}

int main() {
    vector<int> nums = {-1,1,2};
    cout << smallestAbsent(nums);
    return 0;
}

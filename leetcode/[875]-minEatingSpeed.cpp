//
// Created by sanenchen on 25-9-11.
//
#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    // check 函数
    auto check = [&](int mid)-> bool {
        long long sumHour = 0;
        for (auto& i : piles)
            sumHour += (mid + i - 1) / mid;
        return sumHour <= h;
    };
    int left = 0, right = 0;
    for (auto& i : piles)
        right = max(right, i);
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    vector<int> piles = {3,6,7,11};
    cout << minEatingSpeed(piles, 8);
    return 0;
}
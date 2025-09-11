//
// Created by sanenchen on 25-9-10.
//
#include <bits/stdc++.h>
using namespace std;

int numFriendRequests(vector<int> &ages) {
    int cnt[121]{};
    for (auto &i: ages)
        cnt[i]++;
    int left = 0, cnt_window = 0, ans = 0; // left 是左窗口边界 也就是比较小的age
    for (int right = 0; right < 121; ++right) {
        cnt_window += cnt[right];
        while (left * 2 <= right + 14) {
            cnt_window -= cnt[left];
            left++;
        }
        if (cnt_window > 0)
            ans += cnt_window * cnt[right] - cnt[right];
    }
    return ans;
}

int main() {
    vector<int> ages = {20,30,100,110,120};
    cout << numFriendRequests(ages);
    return 0;
}

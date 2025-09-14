//
// Created by sanenchen on 25-9-13.
//
#include <bits/stdc++.h>
using namespace std;

int minArrivalsToDiscard(vector<int> &arrivals, int w, int m) {
    int left = 0, ans = 0;
    unordered_map<int, int> cnt;
    unordered_map<int, int> deleted;
    for (int right = 0; right < arrivals.size(); ++right) {
        cnt[arrivals[right]]++;
        if (cnt[arrivals[right]] > m) {
            // 删除掉当前物品
            cnt[arrivals[right]]--;
            ans++;
            deleted[right]++;
        }
        // 判断窗口是否大于了w
        if (right - left + 2 > w) {
            if (deleted[left] == 0) {
                cnt[arrivals[left]]--;
            }
            left++;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {7, 3, 9, 9, 7, 3, 5, 9, 7, 2, 6, 10, 9, 7, 9, 1, 3, 6, 2, 4, 6, 2, 6, 8, 4, 8, 2, 7, 5, 6};
    cout << minArrivalsToDiscard(nums, 10, 1);
    return 0;
}

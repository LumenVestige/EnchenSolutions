//
// Created by sanenchen on 25-7-27.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> nums;
        while (n--) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        int coins = 0;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        while (!nums.empty()) {
            bool flag = false;
            // 寻找目前不需要花钱的最低一个
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < c) {
                    // 免费销毁
                    nums.erase(nums.begin() + i);
                    flag = true;
                    break;
                }
            }
            // 删除并且将每个数翻倍

            if (!flag) {
                nums.erase(nums.begin());
                coins++;
            }
            for (auto &it: nums) {
                it *= 2;
            }
        }
        cout << coins << endl;
    }
    return 0;
}

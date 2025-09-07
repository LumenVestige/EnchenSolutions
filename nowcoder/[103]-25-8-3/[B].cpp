//
// Created by sanenchen on 25-8-3.
//
#include <bits/stdc++.h>
using namespace std;
#define ing long long

bool check(vector<int> nums) {
    int max_n = 0;
    for (auto &it: nums) {
        if (it < max_n)
            return false;
        max_n = max(max_n, it);
    }
    return true;
}

signed main() {
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            if (nums[i] == 1 && nums[next] == 0) {
                cnt++;
            }
        }

        // 转换次数≤1则存在有效断开位置
        if (cnt <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        // // 循环选择i
        // for (int i = 0; i < n; ++i) {
        //     // 断开 i 和 (i + 1) mod n
        //     int i2 = (i + 1) % n;
        //     vector<int> tmp;
        //     if (i2 >= i) {
        //         tmp.assign(nums.begin() + i2, nums.end());
        //         tmp.insert(tmp.end(), nums.begin(), nums.begin() + i + 1);
        //     } else {
        //         tmp.assign(nums.begin() + i2, nums.begin() + i + 1);
        //     }
        //
        //     if (check(tmp)) {
        //         cout << "YES" << endl;
        //         flag = true;
        //         break;
        //     }
        // }
        // if (!flag)
        //     cout << "NO" << endl;
    }
    return 0;
}

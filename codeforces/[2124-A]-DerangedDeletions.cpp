//
// Created by sanenchen on 25-8-1.
//
#include <bits/stdc++.h>
using namespace std;

void check(vector<int>& nums) {
    if (nums.empty()) {
        cout << "NO" << endl;
        return;
    }
    auto tmp_vec = nums;
    sort(tmp_vec.begin(), tmp_vec.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (tmp_vec[i] == nums[i]) {
            nums.erase(nums.begin() + i);
            check(nums);
            return;
        }

    }
    cout << "YES" << endl;
    cout << nums.size() << endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> momo(n, 0);
        // bool fined = false;
        // function<void(int)> dfs = [&](int x) -> void {
        //     if (fined)
        //         return;
        //     if (x == n) {
        //         // 将整个数组构建出来
        //         vector<int> tmp;
        //         for (int i = 0; i < momo.size(); ++i) {
        //             if (momo[i] == 0) {
        //                 tmp.push_back(a[i]);
        //             }
        //         }
        //         // check 一下
        //         if (check(tmp)) {
        //             fined = true;
        //             cout << "YES" << endl;
        //             cout << tmp.size() << endl;
        //             for (auto& it : tmp) {
        //                 cout << it << " ";
        //             }
        //             cout << endl;
        //         }
        //         return;
        //     }
        //
        //     // 0 代表不删 1代表删除
        //     // 删
        //     momo[x] = 1;
        //     dfs(x + 1);
        //     momo[x] = 0; // 回溯
        //     // 不删
        //     momo[x] = 0;
        //     dfs(x + 1);
        //     momo[x] = 1; // 回溯
        // };
        //
        // dfs(0);
        //
        // if (!fined) {
        //     cout << "NO" << endl;
        // }
        check(a);
    }

}
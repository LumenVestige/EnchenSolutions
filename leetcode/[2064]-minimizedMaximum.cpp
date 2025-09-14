#include <bits/stdc++.h>
using namespace std;

int maxRange(vector<int>& nums) {
    int m = 0;
    for (auto& i : nums) {
        m = max(m, i);
    }
    return m;
}

int minimizedMaximum(int n, vector<int>& quantities) {
    auto check = [&](int mid)-> bool {
        // 挨个分配
        vector<int> tmp(quantities);
        int room = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            while (tmp[i] > 0) {
                if (tmp[i] >= mid) tmp[i] -= mid;
                else tmp[i] = 0;
                room++;
            }
        }
        return room <= n;
    };

    int left = 0, right = maxRange(quantities);
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    vector<int> quantities = {11,6};
    cout << minimizedMaximum(6, quantities);
    return 0;
}
//
// Created by sanenchen on 25-9-15.
//
#include <bits/stdc++.h>
using namespace std;

int findKthNumber(int m, int n, int k) {
    auto check = [&](int mid)->bool {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
            cnt += min(mid / i, n);
        return cnt >= k;
    };
    int left = 0, right = m * n;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    cout << findKthNumber(3,3,5);
    return 0;
}
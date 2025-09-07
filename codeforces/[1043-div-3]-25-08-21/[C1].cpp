//
// Created by sanenchen on 25-8-21.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> N(21);
unordered_map<int, int> memo, powN;

// 二分查找
int lowerBound(int target) {
    int left = -1, right = N.size();

    while (left + 1 != right) {
        int mid = left + (right - left) / 2;
        if (N[mid] >= target)
            right = mid;
        else left = mid;
    }
    return right;
}

void solve() {
    int target;
    vector<int> times;
    int ans = 0;
    cin >> target;
    while (target > 0) {
        int tmp = lowerBound(target);
        if (N[tmp] > target)
            tmp--;
        times.push_back(N[tmp]);
        target -= N[tmp];
    }
    for (auto& i : times) {
        //cout << powN[i] << " ";
        ans += pow(3, powN[i] + 1) + powN[i] * pow(3, powN[i] - 1);
    }

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < 21; ++i) {
        N[i] = pow(3, i);
        powN[N[i]] = i;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

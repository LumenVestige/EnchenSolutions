#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // 计算前缀和
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    long long total = prefix[n]; // 总茶包数

    while (q--) {
        int b;
        cin >> b;
        // 检查是否存在至少一种口味的茶包数 >= b
        if (a.back() < b) {
            cout << "-1\n";
            continue;
        }
        long long k = b - 1;
        // 二分找到第一个 > k 的位置
        auto pos = upper_bound(a.begin(), a.end(), k) - a.begin();
        // 计算 sum(min(a[i], k))
        long long sum_min = prefix[pos] + k * (n - pos);
        long long x = sum_min + 1;
        if (x > total) {
            cout << "-1\n";
        } else {
            cout << x << "\n";
        }
    }

    return 0;
}
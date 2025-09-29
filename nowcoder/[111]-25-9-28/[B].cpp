#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sumA = 0, sumB = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sumA += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sumB += b[i];
    }
    // 固定一个，枚举另一个
    int tmp = INT_MIN;
    int ansI, ansJ;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int res = (sumA - a[i]) - (sumB - b[j]);
            if (res > tmp) {
                tmp = res;
                ansI = i + 1;
                ansJ = j + 1;
            }
        }
    }

    cout << ansI << " " << ansJ;
    return 0;
}
//
// Created by sanenchen on 25-7-25.
//
#include <bits/stdc++.h>
using namespace std;

int solve(long long x, long long y, long long k) {
    // 尽量是一次到位
    if (k >= x && k >= y) // 一步到位
        return 1;
    // 下面就要看看是否有且只有一个 就可以把所有的给搞定
    // for (int i = 1; i <= k; i++) {
    //     for (int j = 1; j <= k; j++) {
    //         if (x / i == y / j && x % i == 0 && y % j == 0)
    //             return 1;
    //     }
    // }
    long long temp = gcd(x, y);
    if (x / temp <= k && y / temp <= k)
        return 1;
    return 2; // 否则的话，就用 (0,1) (1,0)慢慢挪吧
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long x, y, k;
        cin >> x >> y >> k;
        cout << solve(x, y, k) << endl;
    }
    return 0;
}

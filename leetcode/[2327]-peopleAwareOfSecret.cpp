//
// Created by sanenchen on 25-9-24.
//
#include <bits/stdc++.h>
using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
    deque<long long> days(forget, 0);
    const int MOD = 1e9 + 7;
    days[forget - 1] = 1;
    long long ans = 0, sum = 0;
    for (int i = 2; i <= n; i++) {
        sum = (sum + days[forget - delay] - days[0] + MOD) % MOD;
        days.pop_front();
        days.push_back(sum);
        if (i > n - forget)
            ans = (ans + sum) % MOD;
    }
    return ans + ((n == forget) ? 1 : 0);
}
int main() {
    cout << peopleAwareOfSecret(6,2,4);
    return 0;
}
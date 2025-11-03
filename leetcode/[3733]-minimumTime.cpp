#include <bits/stdc++.h>
using namespace std;

long long minimumTime(vector<int>& d, vector<int>& r) {
    long long L = lcm(r[0], r[1]);
    int d1 = d[0], d2 = d[1];
    int r1 = r[0], r2 = r[1];
    int l = lcm(r1, r2);
    auto check = [&](long long t) -> bool {
            return d1 <= t - t / r1 && d2 <= t - t / r2 && d1 + d2 <= t - t / l;
    };
    long long left = 0, right = (d[0] + d[1]) * 100LL;
    while (left + 1 != right) {
        long long mid = (left + right) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    } 
    return right;
}

int main() {
    vector<int> d = {3, 1};
    vector<int> r = {2, 3};
    cout << minimumTime(d, r);
    return 0;
}
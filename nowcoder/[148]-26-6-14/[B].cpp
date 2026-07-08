#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MAXM = 1000005;
vector<int> primes;
bool is_prime[MAXM];
void sieve() {
    fill(is_prime, is_prime + MAXM, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXM; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p >= MAXM) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}
void solve() {
    int n; cin >> n;
    // p * p * q
    for (auto& p : primes) {
        if (n % p != 0) continue;
        int cur = n / p;
        int t = sqrt(cur);
        if (t * t == cur) {
            cout << t << " " << p;
            return;
        }
    }
    for (auto& p : primes) {
        if (p*p > n) continue;
        int t = p*p;
        if (n % t == 0) {
            cout << p << " " << n/t;
            return;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    sieve();
    while (T--) {
        solve();
    }
    return 0;
}
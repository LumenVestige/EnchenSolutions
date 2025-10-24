#include <bits/stdc++.h>
using namespace std;
std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
using i128 = __int128;

// 重载输入运算符以支持__int128类型
std::istream &operator>>(std::istream &is, __int128 &val) {
    std::string s;
    bool flag = true;
    is >> s, val = 0;
    if (s[0] == '-') flag = false, val = std::stoi(s.substr(0, 2)), s = s.substr(2);
    for (char &c: s) val = val * 10 + (c - '0') * (!flag ? -1 : 1);
    return is;
}
 
// //重载输出运算符以支持__int128类型
// std::ostream &operator<<(std::ostream &os, __int128 val) {
//     if (val < 0) os << "-", val = -val;
//     if (val > 9) os << val / 10;
//     os << static_cast<char>(val % 10 + '0');
//     return os;
// }
std::ostream &operator<<(std::ostream &os, __int128 val) {
    if (val < 0) os << "-", val = -val;
    if (val > 9) os << val / 10;
    os << static_cast<char>(val % 10 + '0');
    return os;
}
#define int __int128
int mod = 1e9 - 1;
// 快速幂
int qpow(int a, int n) {
    a %= mod;
    int res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
            res %= mod;
        }
        a *= a, a %= mod;
        n >>= 1;
    }
    return res;
}
void solve() {
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    int a1 = qpow(a, d), b1 = qpow(b, e), c1 = qpow(c, f);
    g = (g % mod + mod) % mod;
    if (((a1 + b1 + c1) % mod + mod) % mod == g) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
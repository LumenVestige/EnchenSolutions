//
// Created by sanenchen on 25-8-22.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> N;


// 计算10的n次方
unsigned long long pow10(int n) {
    unsigned long long res = 1;
    for (int i = 0; i < n; ++i) {
        res *= 10;
    }
    return res;
}

// 计算0到x中数字i出现的总次数
long long countUpTo(unsigned long long x, int i) {
    if (x < 0) return 0;
    long long res = 0;
    unsigned long long pow10_val = 1;

    while (pow10_val <= x) {
        unsigned long long high = x / (pow10_val * 10);
        unsigned long long cur = (x / pow10_val) % 10;
        unsigned long long low = x % pow10_val;

        if (i == 0) {
            // 0不能作为最高位，高位需减1
            if (high > 0) {
                res += (high - 1) * pow10_val;
            }
        } else {
            res += high * pow10_val;
        }

        // 处理当前位
        if (cur > i) {
            res += pow10_val;
        } else if (cur == i) {
            res += low + 1;
        }

        // 修正0在最高位的多算情况
        if (i == 0 && pow10_val > x / 10) {
            res -= pow10_val;
        }

        pow10_val *= 10;
    }
    return res;
}

// 计算[L, R]区间内数字i出现的总次数
long long countInRange(unsigned long long L, unsigned long long R, int i) {
    if (L > R) return 0;
    return countUpTo(R, i) - countUpTo(L - 1, i);
}

// 计算d位数完整区间（10^(d-1)到10^d-1）中i出现的次数
long long countInFullD(int d, int i) {
    if (d == 0) return 0;
    if (i == 0) {
        if (d == 1) return 0;  // 1位数中没有0（从1开始）
        return (d - 1) * 9 * pow10(d - 2);
    } else {
        return pow10(d - 1) + (d - 1) * 9 * pow10(d - 2);
    }
}

// 主函数：计算序列前k个数字中i出现的次数
long long countKthDigit(unsigned long long k, int i) {
    if (i < 0 || i > 9) return 0;

    long long total = 0;
    int d = 1;
    unsigned long long start = 1;
    unsigned long long count = 9;
    unsigned long long sum_len = 0;

    while (true) {
        unsigned long long len = count * d;
        if (sum_len + len < k) {
            // 完整包含当前区间，累加次数
            total += countInFullD(d, i);
            sum_len += len;
            d++;
            start *= 10;
            count *= 10;
        } else {
            // 处理不完整区间
            unsigned long long rem = k - sum_len;
            unsigned long long m = rem / d;
            int r = rem % d;

            // 累加完整数字的次数
            if (m > 0) {
                unsigned long long end = start + m - 1;
                total += countInRange(start, end, i);
            }

            // 累加最后一个数字前r位的次数
            if (r > 0) {
                unsigned long long num = start + m;
                string s = to_string(num);
                for (int j = 0; j < r && j < s.size(); ++j) {
                    if (s[j] - '0' == i) {
                        total++;
                    }
                }
            }
            break;
        }
    }

    return total;
}

void solve() {
    int k;
    cin >> k;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += i * countKthDigit(k, i);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

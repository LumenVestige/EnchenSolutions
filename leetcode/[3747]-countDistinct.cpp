#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 能力不够，卡三天了。。。
// 先跳过了
long long countDistinct(long long n) {
    string s = to_string(n);
    int m = s.size();

    // 计算长度小于 m 的不含 0 的整数个数
    // 9^1 + 9^2 + ... + 9^(m-1) = (9^m - 9) / 8
    long long pow9 = pow(9, m);
    long long ans = (pow9 - 9) / 8;

    // 计算长度恰好等于 m 的不含 0 的整数个数
    for (int i = 0; i < m; i++) {
        char d = s[i];
        if (d == '0') { // 只能填 0，不合法，跳出循环
            break;
        }
        // 这一位填 1 到 d-1，后面的数位可以随便填 1 到 9
        int v = d - '1';
        if (i == m - 1) {
            v++; // 最低位可以等于 d
        }
        pow9 /= 9;
        ans += v * pow9;
        // 然后，这一位填 d，继续遍历
    }

    return ans;
}

int main() {
    cout << countDistinct(1000);
    return 0;
}
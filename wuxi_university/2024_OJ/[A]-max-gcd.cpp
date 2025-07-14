//
// Created by sanenchen on 25-7-13.
//
#include "../WuXiUniversity.h"

#include "stdc++.h"
using namespace std;

void WuxiUniversity::max_gcd() {
    long long n, m;
    cin >> n >> m;
    // 思路：一直加加加 加到值开始减小
    // 随后一直减减减，减到开始减小
    // 比较那两个值
    if (n == 0 && m == 0) {
        cout << 0;
        return ;
    }
    long long temp_n1 = LONG_LONG_MIN, temp_n2 = LONG_LONG_MIN;
    long long temp_a = n, temp_b = m;
    long long temp_gcd = gcd(temp_a, temp_b);
    while (temp_a != temp_b) {
        temp_n1 = max(temp_gcd,temp_n1);
        temp_a++;temp_b--;
        temp_gcd = gcd(temp_a, temp_b);
    }
    temp_n1 = max(temp_gcd,temp_n1);
    temp_a = n; temp_b = m;
    temp_gcd = gcd(temp_a, temp_b);
    while (temp_a != temp_b) {
        temp_n2 = max(temp_gcd,temp_n2);
        temp_b++;temp_a--;
        temp_gcd = gcd(temp_a, temp_b);
    }
    temp_gcd = gcd(temp_a, temp_b);
    cout << max(temp_n1, temp_n2);

}

int gcd(long long n, long long m) {
    // 判断是否为双0的特殊情况
    if (n == 0 && m == 0) {
        return 0;
    }
    if (m > n)
        swap(n, m);
    while (n % m != 0) {
        n = m;
        m = n % m;
    }
    return m;
}

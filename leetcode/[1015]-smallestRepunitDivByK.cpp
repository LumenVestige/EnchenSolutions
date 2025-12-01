#include <bits/stdc++.h>
using namespace std;

int smallestRepunitDivByK(int k) {
    unordered_set<int> cnt;
    // 根据取模：下一个数 = （上一个数字 x 10 + 1）
    // 所以 下一个数 % k = [(上一个数 % k) * (10 % k) + (1 % k)] % k
    // 取模运算的性质：(a + b) % m = [(a % m) + (b % m)] % m。
    // 余数 = （上一个数字 * 10 + 1）% k = (上一个数字 % k * 10 + 1) % k
    int x = 1 % k;
    int ans = 1;
    while (true) {
        // 先判断是否为0
        if (x == 0) {
            return ans;
        }
        // 检查是否存在了
        if (cnt.count(x)) {
            return -1;
        }
        // 不存在，插入当前
        cnt.insert(x);
        // 计算新的余数
        x = (x * 10 + 1) % k;
        // 数量++
        ans++;
    }
    return -1;
}

int main() {
    cout << smallestRepunitDivByK(3);
    return 0;
}
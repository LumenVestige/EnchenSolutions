#include <bits/stdc++.h>
using namespace std;

// 计算第x位fib
int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    cout << fib(3);
    return 0;
}
//
// Created by sanenchen on 25-7-24.
//
// 跳台阶
// https://www.acwing.com/problem/content/823/
/**
*一个楼梯共有 n
级台阶，每次可以走一级或者两级，问从第 0
级台阶走到第 n
级台阶一共有多少种方案。
**/
#include <bits/stdc++.h>

using namespace std;
// 加入记忆化搜索
unordered_map<int, int> g_map;
int fibonacci(int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    // 判断是否在记忆化搜索中
    if (g_map.find(x) != g_map.end())
        return g_map[x];
    int temp = fibonacci(x - 1) + fibonacci(x - 2);
    g_map[x] = temp;
    return temp;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
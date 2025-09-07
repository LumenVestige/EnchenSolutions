//
// Created by sanenchen on 25-7-27.
//
#include <bits/stdc++.h>

#include <utility>
using namespace std;
// // 记忆化搜索
unordered_map<string, int> g_map;
void solve(int l, string str) {
    auto check = [&](string str) -> bool {
        for (int i = 0; i < str.length(); i++) {
            if (i >= 1)
                if (str[i] == str[i - 1])
                    return false;
        }
        return true;
    };
    function<int(int, string, int)> dfs = [&](int n, string c, int oper) -> int {
        if (check(c))
            return oper;
        if (n == l - 1) {
            if (!check(c))
                return -1;
        }
        auto cir = [](char s) -> char {
            if (s == '0')
                return '1';
            return '0';
        };
        // 进来后 就要看 变还是不变
        // 不变
        int oper2 = oper;
        oper2 = dfs(n + 1, c, oper2);
        // 变
        int oper1 = oper + 1;
        c[n + 1] = cir(c[n + 1]);
        c[n] = cir(c[n]);
        oper1 = dfs(n + 1, c, oper1);

        if (oper1 == -1 || oper2 == -1) {
            if (oper1 != -1)
                return oper1;
            if (oper2 != -1)
                return oper2;
            return -1;
        }
        int temp = min(oper1, oper2);
        g_map[c] = temp;
        return temp;
    };
    cout << dfs(0, std::move(str), 0) << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        string str;
        cin >> l >> str;
    }
    return 0;
}

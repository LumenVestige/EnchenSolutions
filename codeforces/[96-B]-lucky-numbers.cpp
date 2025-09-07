//
// Created by sanenchen on 25-7-25.
//
#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, pair<int, int> > g_map;
long long base_n;
bool isSupLucky(long long n) {
    int x = 0, y = 0, c = 0;
    if (n < base_n)
        return false;
    while (n != 0) {
        // 先判断在g_map中是否有这个数
        if (g_map.find(n) != g_map.end()) {
            x += g_map[n].first;
            y += g_map[n].second;
            if (x == y)
                return true;
            return false;
        }

        const long long temp = n % 10;
        n /= 10;
        if (temp == 4)
            x++;
        if (temp == 7)
            y++;
        c++;
    }

    // 将当前判断的数放进map中
    g_map[n] = {x, y};
    if (x == y && x + y == c)
        return true;
    return false;
}

int main() {

    cin >> base_n;
    // 用bfs 以此增增为4或者7 直到可以为止
    queue<long long> q;
    q.emplace(0);
    while (!q.empty()) {
        long long current = q.front();
        q.pop();
        if (isSupLucky(current)) {
            cout << current;
            return 0;
        }
        q.emplace(current * 10 + 4);
        q.emplace(current * 10 + 7);

    }

    // while (true) {
    //     if (isSupLucky(n)) {
    //         cout << n;
    //         return 0;
    //     }
    //     n += 1;
    // }
}

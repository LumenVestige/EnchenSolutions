//
// Created by sanenchen on 25-8-22.
//
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, bool> goods;

bool checkGood(int num, int i) {
    if (num == 0) return true;
    int last = num % 10;
    bool check = false;
    // 记忆化搜素查询
    if (goods.find(num) != goods.end())
        if (i % 2 != 0)
            return goods[num];
        else return !goods[num];
    if (i % 2 == 0) {
        if (last % 2 == 0)
            check = checkGood(num / 10, i + 1);
        else check = false;
    } else {
        if (last % 2 != 0)
            check = checkGood(num / 10, i + 1);
        else check = false;
    }
    goods[num] = check;
    return check;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (checkGood(i, 1)) {
            cout << i << endl;
            ans++;
        }

    }
    cout << ans;
    return 0;
}

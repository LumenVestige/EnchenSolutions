//
// Created by sanenchen on 25-7-27.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // bfs
    int n;
    cin >> n;
    auto checkGoodSub = [&](string str) -> bool {
        if (str.length() < n) {
            return false;
        }
        for (int i = 0; i < str.length(); i++) {
            if (i >= 1)
                if (str[i] == str[i - 1])
                    return false;
        }
        return true;
    };
    int ans = 0;
    queue<string> q;
    q.emplace("");
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        // 判断长度
        if (current.length() <= n) {
            if (checkGoodSub(current)) {
                ans += 1;
            }
        } else
            break;
        q.push(current + "0");
        q.push(current + "1");
    }
    cout << ans;
    return 0;
}
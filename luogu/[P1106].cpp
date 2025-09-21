//
// Created by sanenchen on 25-9-21.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int k;
    cin >> s >> k;
    while (k--) {
        for (int i = 0; i < s.size(); ++i) {
            // 找到下降点
            // 当前的这个数大于后一个数 则删除这个数
            if (i < s.size() - 1 && s[i] > s[i + 1]) {
                s.erase(s.begin() + i);
                break;
            }
            if (i == s.size() - 1) {
                s.erase(s.begin() + i);
            }
        }
    }
    // 去除前导0
    int p = 0;
    while (p != 0) {
        if (s[p] == '0') {
            s.erase(s.begin());
        }
    }
    cout << s;
    return 0;
}
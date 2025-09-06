//
// Created by sanenchen on 25-8-17.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
char shiftChar(char c, int t) {
    // 确保t为正数，取模26避免不必要的循环
    t = t % 26;
    if (t < 0) t += 26; // 处理负数情况

    // 计算移动后的字符
    int originalPos = c - 'a';
    int newPos = (originalPos + t) % 26;
    return 'a' + newPos;
}
string shiftingLetters(string s, vector<int>& shifts) {
    vector<int> diff(shifts.size() + 1, 0);

    for (int i = 0; i < shifts.size(); ++i) {
        // if (s[i] + shifts[i] > 'z') {
        //     s[i] = s[i] + shifts[i] - 'z';
        // } else s[i] = s[i] + shifts[i];
        diff[0] += shifts[i];
        diff[i + 1] -= shifts[i];
    }
    // 还原出来加的次数
    vector<int> times(shifts.size(), 0);
    times[0] = diff[0];
    for (int i = 1; i < times.size(); ++i) {
        times[i] = times[i - 1] + diff[i];
    }
    for (int i = 0; i < times.size(); ++i) {
        s[i] = shiftChar(s[i], times[i]);
    }
    return s;
}

signed main() {

    vector<int> shift = {10,20,30};
    cout << shiftingLetters("bad", shift);
    return 0;
}
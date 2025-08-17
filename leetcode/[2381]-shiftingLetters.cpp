//
// Created by sanenchen on 25-8-17.
//
#include <bits/stdc++.h>
using namespace std;
char shiftChar(char c, int t) {
    // 确保t为正数，取模26避免不必要的循环
    t = t % 26;
    if (t < 0) t += 26; // 处理负数情况

    // 计算移动后的字符
    int originalPos = c - 'a';
    int newPos = (originalPos + t) % 26;
    return 'a' + newPos;
}
string shiftingLetters(string s, vector<vector<int>>& shifts) {
    vector<int> diff(s.size() + 1);
    // 差分数组
    for (auto& it : shifts) {
        diff[it[0]] += (it[2] == 1) ? 1 : -1;
        diff[it[1] + 1] -= (it[2] == 1) ? 1 : -1;
    }
    // 还原
    vector<int> times(s.size());
    times[0] = diff[0];
    for (int i = 1; i < times.size(); ++i) {
        times[i] = times[i - 1] + diff[i];
    }
    for (int i = 0; i < times.size(); ++i) {
        s[i] = shiftChar(s[i], times[i]);
    }

    return s;
}
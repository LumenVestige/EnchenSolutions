#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,d;
    string s;
    cin >> n >> d >> s;
    // 两个hash表 一个标准的 一个当前拥有的
    unordered_map<char, int> cnt;
    for (auto& i : s) {
        cnt[i]++;
    }
    string ts = s;
    sort(ts.begin(), ts.end(), [](char a, char b) {
        return a > b;
    });
    // 暴力枚举
    for (int i = 1; i < stoi(ts) / d; ++i) {
        string tmp = to_string(i * d);
        unordered_map<char, int> targetCnt;
        for (auto& i : tmp) {
            targetCnt[i]++;
        }
        // 判断target里面是否有
        bool flag = false;
        for (auto& [a, b] : targetCnt) {
            if (cnt.count(a) == 0 || cnt[a] < b) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        cout << i * d;
        return 0;
    }
    cout << "-1";
    return 0;
}
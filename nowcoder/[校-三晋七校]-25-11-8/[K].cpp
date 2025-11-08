#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = s;
    vector<int> diff(n + 1, 0);
    int times = 0;
    for (int i = 0; i < n; ++i) {
        if (times % 2 == 1) {
            if (s[i] == '1') s[i] = '0'; else s[i] = '1';
        }
        // 按照规则进行当前反转
        if (s[i] == '1') {
            times++;
        }
    }
    // vector<int> cnt(n + 1, 0);
    // for (int i = 1; i <= n; ++i) {
    //     cnt[i] = cnt[i - 1] + diff[i - 1];
    // }
    // for (int i = 0; i < n; ++i) {
    //     int times = cnt[i + 1] % 2;
    //     if (times == 1) {
    //         // 反转
    //         if (ans[i] == '1') ans[i] = '0';
    //         else ans[i] = '1';
    //     }
    // }
    cout << s;
    return 0;
}
//
// Created by sanenchen on 25-10-20.
//
#include <bits/stdc++.h>
using namespace std;

// 判断是否符合条件
bool check(unordered_map<char, int> &cnt) {
    if (cnt['1'] == cnt['2'] && cnt['2'] == cnt['3'])
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    // 双指针
    int left = 0, ans = 0;
    // unordered_map<char, int> cnt;
    // for (int right = 0; right < n; ++right) {
    //     // 入
    //     cnt[str[right]]++;
    //     if (check(cnt)) {
    //         ans++;
    //     }
    //     // 判断
    //     while (!check(cnt) && right <= left) {
    //         if (check(cnt)) {
    //             ans++;
    //         }
    //         // 左出
    //         cnt[str[left]]--;
    //         left++;
    //     }
    // }
    // cout << ans;
    // 搜索
    vector<int> n1(n + 1, 0), n2(n + 1, 0), n3(n + 1, 0);
    unordered_map<string, int> cnt;
    for (int i = 1; i <= n; ++i) {
        n1[i] = n1[i - 1] + ((str[i - 1] == '1') ? 1 : 0);
        n2[i] = n2[i - 1] + ((str[i - 1] == '2') ? 1 : 0);
        n3[i] = n3[i - 1] + ((str[i - 1] == '3') ? 1 : 0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int a = n1[j + 1] - n1[i];
            int b = n2[j + 1] - n2[i];
            int c = n3[j + 1] - n3[i];
            if (a == b && b == c && a != 0) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
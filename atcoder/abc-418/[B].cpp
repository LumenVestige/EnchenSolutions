//
// Created by sanenchen on 25-8-9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    long double tmp_rate = 0;
    // 双指针
    for (int l = 0; l < str.size() - 1; ++l) {
        if (str[l] == 't') {
            long double count_t = 1;
            double r = l;
            for (int i = l + 1; i < str.size(); ++i) {
                if (str[i] == 't') {
                    count_t++;
                    r = i;
                    if (l == r) {
                        continue;
                    }
                    string tmp = str.substr(l, r - l + 1);
                    if (tmp.size() < 3) {
                        continue;
                    }
                    long double tmps = (count_t - 2) / ((long double)tmp.size() - 2);
                    tmp_rate = max(tmp_rate, tmps);
                }
            }
        }
    }

    cout << std::fixed << std::setprecision(17) << tmp_rate;

    // int l = -1, r = str.size();
    // long double count_t = 0;
    // for (int i = 0; i < str.size(); ++i) {
    //     if (l == -1 && str[i] == 't')
    //         l = i;
    //     if (str[i] == 't') {
    //         r = i;
    //         count_t++;
    //     }
    // }
    // if (l == -1 && r == str.size()) {
    //     cout << 0;
    //     return 0;
    // }
    // string tmp = str.substr(l, r - l + 1);
    // if (tmp.size() < 3) {
    //     cout << 0;
    //     return 0;
    // }
    // long double tmps = (count_t - 2) / ((long double)tmp.size() - 2);
    // if (tmps < 0) {
    //     cout << 0;
    //     return 0;
    // }
    // cout << std::fixed << std::setprecision(17) << tmps;
    return 0;
}

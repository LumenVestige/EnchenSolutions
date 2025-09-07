//
// Created by sanenchen on 25-8-30.
//
#include <bits/stdc++.h>
using namespace std;

// int score(vector<string> &cards, char x) {
//     vector<char> count_l, count_r;
//     int count_d = 0;
//     for (auto &it: cards) {
//         if (it[0] == x && it[1] == x) count_d++;
//         else if (it[0] == x) count_l.push_back(it[1]);
//         else if (it[1] == x) count_r.push_back(it[0]);
//     }
//     // 消消乐
//     int ans = 0;
//     for (auto i = count_l.begin(); i != count_l.end();) {
//         bool del = false;
//         for (auto j = next(i); j != count_l.end();) {
//             if (*i != *j) {
//                 j = count_l.erase(j);
//                 ans++;
//                 del = true;
//                 break;
//             }
//             ++j;
//         }
//         if (del)i = count_l.erase(i);
//         else ++i;
//     }
//
//     for (auto i = count_r.begin(); i != count_r.end();) {
//         bool del = false;
//         for (auto j = next(i); j != count_r.end();) {
//             if (*i != *j) {
//                 j = count_r.erase(j);
//                 ans++;
//                 del = true;
//                 break;
//             }
//             ++j;
//         }
//         if (del)i = count_r.erase(i);
//         else ++i;
//     }
//     ans += (count_l.size() + count_r.size() >= count_d) ? count_d : count_l.size() + count_r.size();
//     return ans;
// }
int score(vector<string>& cards, char x) {
    // 统计牌的频率
    unordered_map<string, int> cnt;
    for (auto &s : cards) cnt[s]++;

    // sm[0/1]：某一类牌的总数
    // mx[0/1]：某一类牌的最大频率
    // t：特殊的 xx 有几张
    int sm[2] = {0}, mx[2] = {0}, t = 0;
    for (auto &p : cnt) {
        if (p.first[0] == x && p.first[1] == x) {
            t += p.second;
        } else if (p.first[0] == x) {
            sm[0] += p.second;
            mx[0] = max(mx[0], p.second);
        } else if (p.first[1] == x) {
            sm[1] += p.second;
            mx[1] = max(mx[1], p.second);
        }
    }

    // leetcode 1953 的结论
    auto calc = [&](int sm, int mx) {
        if (mx > sm - mx) return sm - mx;
        else return sm / 2;
    };

    int ans = 0;
    // 枚举把 i 张 xx 分给第一类牌，剩下的 t - i 张分给第二类牌
    for (int i = 0; i <= t; i++) {
        int x = calc(sm[0] + i, max(mx[0], i));
        int y = calc(sm[1] + t - i, max(mx[1], t - i));
        ans = max(ans, x + y);
    }
    return ans;
}


int main() {
    vector<string> cards = {"ba", "bc", "ba"};
    cout << score(cards, 'b');
    return 0;
}

//
// Created by sanenchen on 25-8-9.
//
#include <bits/stdc++.h>

using namespace std;

class MyCalendar {
private:
    vector<bool> mx;
    vector<pair<int, int>> booked;
    // void maintain(int o) {
    //     mx[o] = (mx[o * 2] || mx[o * 2 + 1]);
    // }
    // void build(int o, int l, int r) {
    //     if (l == r) {
    //         mx[o] = org[l];
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     build(o * 2, l, m);
    //     build(o * 2 + 1, m + 1, r);
    //     maintain(o);
    // }
    // bool query(int o, int l, int r, int ql, int qr) {
    //     // 如果ql-qr在l-r子区间内
    //     if (ql <= l && qr >= r) {
    //         return mx[o];
    //     }
    //     int m = (l + r) / 2;
    //     int res = false;
    //     // 左半区间 [l, m] 右半区间[m + 1, r]
    //     // 是否与左半区间右重叠
    //     if (ql <= m) {
    //         res = query(o * 2, l, m, ql, qr);
    //     }
    //     if (qr >= m + 1) {
    //         res = (query(o * 2 + 1, m + 1, r, ql, qr) || res);
    //     }
    //     return res;
    // }
public:
    MyCalendar() {
        org.clear();
    }

    bool book(int startTime, int endTime) {
        for (auto& [l, r] : booked) {
            if (l <= startTime && r >= endTime)
                return false;
        }
        booked.push_back({startTime, endTime});
    }
};

int main() {

}
//
// Created by sanenchen on 25-8-9.
//
#include <bits/stdc++.h>

using namespace std;


// 可以用线段树快速判断
class MyCalendar {
    unordered_map<int, int> mx;
    void build(int o, int l, int r) {
        if (l == r) {
            mx[o] = 0;
            return;
        }
        int m = (l + r) / 2;
        // 构建左
        build(o * 2, l, m);
        build(o * 2 + 1, m + 1, r);
        // 维持
        mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
    }
    void update(int index, int val, int o, int l, int r) {
        if (l == r && l == index) {
            mx[o] = val;
        }
        int m = (l + r) / 2;
        if (m >= index) {
            // 左边更新
            update(index, val, o * 2, l, m);
        }
        if (m < index) {
            // 右边更新
            update(index, val, o * 2 + 1, m + 1, r);
        }
        mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
    }
    int query(int l, int r, int o, int ql, int qr) {
        if (l <= ql && r >= qr) {
            return mx[o];
        }
        int m = (l + r) / 2;
        int res = INT_MIN;
        if (m >= ql) {
            // 左
            res = min(res, query(l, m, o * 2, ql, qr));
        }
        if (m + 1 <= qr) {
            // 右
            res = min(res, query(l, m, o * 2, ql, qr));
        }
        return res;
    }
public:
    MyCalendar() {
        build(1, 0, 1e9 + 1);
    }
    
    bool book(int startTime, int endTime) {
        // 查询
        if (query(0, 1e9, 1, startTime, endTime)) {
            return false;
        }
        for (int i = startTime; i <= endTime; ++i) {
            update(i, 1, 1, 0, 100000000);
        }
        return true;
    }
};
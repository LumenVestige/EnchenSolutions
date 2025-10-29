//
// Created by sanenchen on 25-8-9.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class MyCalendar {
private:
    unordered_map<ll, int> mx;
    unordered_map<ll, int> lazy;
    void pushdown(ll o) {
        if (lazy[o] != 0) {
            lazy[o * 2] = 1;
            mx[o * 2] = 1;
            lazy[o * 2 + 1] = 1;
            mx[o * 2 + 1] = 1;
            lazy[o] = 0;
        }
    }
    void build(ll o, int l, int r) {
        // if (l == r) {
        //     mx[o] = 0;
        //     return;
        // }
        // int mid = l + (r - l) / 2;
        // build(o * 2, l, mid);
        // build(o * 2 + 1, mid + 1, r);
        // mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
    }
    void update(ll o, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr) {
            mx[o] = 1;
            return;
        }
        pushdown(o);
        int mid = l + (r - l) / 2;
        if (mid >= ql) 
            update(o * 2, l, mid, ql, qr);
        if (mid + 1 <= qr) 
            update(o * 2 + 1, mid + 1, r, ql, qr);
        mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
    }
    int query(ll o, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr) {
            return mx[o];
        }
        pushdown(o);
        int mid = l + (r - l) / 2;
        int ans = 0;
        if (mid >= ql)
            ans += query(o * 2, l, mid, ql, qr);
        if (mid + 1 <= qr)
            ans += query(o * 2 + 1, mid + 1, r, ql, qr);
        return ans;
    }

public:
    MyCalendar() {
        build(1, 0, 100000000);
    }
    
    bool book(int startTime, int endTime) {
        // 先查
        if (query(1, 0, 1e9, startTime, endTime - 1) >= 1) {
            return false;
        }
        update(1, 0, 1e9, startTime, endTime - 1);
        return true;
    }
};

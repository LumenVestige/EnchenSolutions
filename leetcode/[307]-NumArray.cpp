//
// Created by sanenchen on 25-8-8.
//
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> mx;
    size_t n;
    void maintain(int o) {
        mx[o] = mx[o * 2] + mx[o * 2 + 1];
    }

    void build(const vector<int>& a, int o, int l, int r) {
        if (l == r) { // 到达一个末端子节点了
            mx[o] = a[l];
            return;
        }
        int m = (l + r) / 2;
        // 先完成左树
        build(a, o * 2, l, m);
        // 在完成右树
        build(a, o * 2 + 1, m + 1, r);
        maintain(o); // 维持
    }

    int query(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return mx[o];
        }
        int m = (l + r) / 2;
        int sum = 0;
        // 左半区间：[l, m],右半区间：[m + 1, r]
        // 查询区间是否与左半区间重叠？
        if (ql <= m)
            sum += query(o * 2, l, m, ql, qr);
        // 查询区间是否与右区间重叠？
        if (qr >= m + 1)
            sum += query(o * 2 + 1, m + 1, r, ql, qr);
        return sum;
    }

    void update(int o, int l, int r, int index, int val) {
        if (l == r && l == index) {
            mx[o] = val;
            return;
        }
        int m = (l + r) / 2;
        if (m < index) {
            update(o * 2 + 1, m + 1, r, index, val);
        }
        if (m >= index) {
            update(o * 2, l, m, index, val);
        }
        maintain(o);
    }

public:
    NumArray(vector<int>& nums) {
        // 构建树
        n = nums.size();
        mx.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void update(int index, int val) {
        update(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};


int main() {

}
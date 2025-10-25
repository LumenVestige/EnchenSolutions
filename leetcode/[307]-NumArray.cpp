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

// class NumArray {
// private:
//     vector<int> mx;
//     size_t n;
//     void maintain(int o) {
//         mx[o] = mx[o * 2] + mx[o * 2 + 1];
//     }

//     void build(const vector<int>& a, int o, int l, int r) {
//         if (l == r) { // 到达一个末端子节点了
//             mx[o] = a[l];
//             return;
//         }
//         int m = (l + r) / 2;
//         // 先完成左树
//         build(a, o * 2, l, m);
//         // 在完成右树
//         build(a, o * 2 + 1, m + 1, r);
//         maintain(o); // 维持
//     }

//     int query(int o, int l, int r, int ql, int qr) {
//         if (ql <= l && r <= qr) {
//             return mx[o];
//         }
//         int m = (l + r) / 2;
//         int sum = 0;
//         // 左半区间：[l, m],右半区间：[m + 1, r]
//         // 查询区间是否与左半区间重叠？
//         if (ql <= m)
//             sum += query(o * 2, l, m, ql, qr);
//         // 查询区间是否与右区间重叠？
//         if (qr >= m + 1)
//             sum += query(o * 2 + 1, m + 1, r, ql, qr);
//         return sum;
//     }

//     void update(int o, int l, int r, int index, int val) {
//         if (l == r && l == index) {
//             mx[o] = val;
//             return;
//         }
//         int m = (l + r) / 2;
//         if (m < index) {
//             update(o * 2 + 1, m + 1, r, index, val);
//         }
//         if (m >= index) {
//             update(o * 2, l, m, index, val);
//         }
//         maintain(o);
//     }

// public:
//     NumArray(vector<int>& nums) {
//         // 构建树
//         n = nums.size();
//         mx.resize(4 * n);
//         build(nums, 1, 0, n - 1);
//     }

//     void update(int index, int val) {
//         update(1, 0, n - 1, index, val);
//     }

//     int sumRange(int left, int right) {
//         return query(1, 0, n - 1, left, right);
//     }
// };


// 再次复习线段树 2025.10.25
// 实现线段树
class NumArray {
private:
    vector<int> t;
    int size = 0;
    // 递归方法：构建一个线段树，不会返回，但是执行只有会将当前的左右俩子树填充完毕
    // 参数：左 右 原数组 当前的位置
    void build(int left, int right, vector<int>& a, int o) {
        if (left == right) {
            t[o] = a[0];
            return;
        }
        int mid = (left + right) / 2;
        // 构建左子树
        build(left, mid, a, o * 2);
        // 构建右子树
        build(mid + 1, right, a, o * 2 + 1);
        // 左右子树构建完毕，现在开始维持
        t[o] = t[o * 2] + t[o * 2 + 1];
    }
    // 修改函数，传入那个index 和 val值 我们要根据其中的值修改，并且还要维持这个子树
    void update(int l, int r, int index, int val, int o) {
        if (l == r && l == index) {
            t[o] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (mid >= index) {
            update(l, mid, index, val, o * 2);
        } else {
            update(mid + 1, r, index, val, o * 2 + 1);
        }
        // 返回的时候就要维护
        t[o] = t[o * 2] + t[o * 2 + 1];
    }
    // 查询区间
    int query(int o, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr) {
            return t[o];
        }
        int sum = 0;
        int mid = (l + r) / 2;
//         // 左半区间：[l, m],右半区间：[m + 1, r]
//         // 查询区间是否与左半区间重叠？
//         if (ql <= m)
//             sum += query(o * 2, l, m, ql, qr);
//         // 查询区间是否与右区间重叠？
//         if (qr >= m + 1)
//             sum += query(o * 2 + 1, m + 1, r, ql, qr);
        // 左区间
        if (mid >= ql) {
            sum += query(o * 2, l, mid, ql, qr);
        }
        if (mid + 1 <= qr) {
            sum += query(o * 2 + 1, mid + 1, r, ql, qr);
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        t.resize(nums.size() * 4);
        this->size = nums.size();
    }

    void update(int index, int val) {
        this->update(0, size - 1, index, val, 0);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, size - 1, left, right);
    }
};

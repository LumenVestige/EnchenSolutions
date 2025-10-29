//
// Created by sanenchen on 25-8-6.
//
#include <bits/stdc++.h>

using namespace std;

// class SegmentTree {
// private:
//     vector<int> mx;

//     void maintain(int o) {
//         mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
//     }

//     // 构建线段树
//     void build(const vector<int> &a, int o, int l, int r) {
//         if (l == r) {
//             // 无法拆分了 此时就是叶子节点了
//             mx[o] = a[l];
//             return;
//         }
//         int m = (l + r) / 2;
//         // 构建左
//         build(a, o * 2, l, m);
//         // 构建右
//         build(a, o * 2 + 1, m + 1, r);
//         maintain(o);
//     }

// public:
//     // 构造函数 根据原始a构建
//     SegmentTree(const vector<int>& a) {
//         size_t n = a.size();
//         // std::bit_width();
//         mx.resize(4 * n);
//         // 从头开始构建
//         build(a, 1, 0, n - 1);
//     }

//     int findFirstAndUpdate(int o, int l, int r, int x) {
//         if (mx[o] < x) {
//             return -1;
//         }
//         // 找到了！ 是单个元素 到最底层了 那么就要 更新为 -1
//         if (l == r) {
//             mx[o] = -1;
//             return l;
//         }
//         int m = (l + r) / 2;
//         // 先左边
//         int i = findFirstAndUpdate(o * 2, l, m, x);
//         if (i < 0)
//             i = findFirstAndUpdate(o * 2 + 1, m + 1, r, x);
//         maintain(o);
//         return i;
//     }

// };


// int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
//     SegmentTree t(baskets);
//     int ans = 0;
//     for (auto& it : fruits) {
//         if (t.findFirstAndUpdate(1, 0, baskets.size() - 1, it) < 0) {
//             ans ++;
//         }
//     }
//     return ans;
// }


class SegementTree {
    vector<int> mx;
    void maintain(int o) {
        mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
    }
    void build(int o, int l, int r, vector<int>& nums) {
        if (l == r) {
            mx[o] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(o * 2, l, mid, nums);
        build(o * 2 + 1, mid + 1, r, nums);
        maintain(o);
    }
public:
    SegementTree(int n, vector<int>& nums) {
        mx = vector<int>(n * 4);
        build(1, 0, n - 1, nums);
    }
    bool queryTargetAndUpdate(int o, int l, int r, int target) {
        if (l == r && mx[o] >= target) {
            mx[o] = -1;
            return true;
        }
        bool state = false;
        int mid = l + (r - l) / 2;
        // 如果当前的左边大于 就往左边去
        if (mx[o * 2] >= target) {
            state = max(state, queryTargetAndUpdate(o * 2, l, mid, target));
        }
        if (state == false && mx[o * 2 + 1] >= target) {
            state = max(state, queryTargetAndUpdate(o * 2 + 1, mid + 1, r, target));
        }
        maintain(o);
        return state;
    }
};

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    SegementTree tree(baskets.size(), baskets);
    int ans = 0;
    for (auto& i : fruits) {
        if (!tree.queryTargetAndUpdate(1, 0, baskets.size() - 1, i)) {
            ans++;
        }
    }
    return ans;
}

int main() {
    vector<int> n1 = {4, 2, 5};
    vector<int> n2 = {3, 5, 4};
    cout << numOfUnplacedFruits(n1, n2);
    return 0;
}
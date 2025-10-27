#include <bits/stdc++.h>
using namespace std;

class LazySegementTree {
    vector<int> ones;   // 记录区间内 1 的个数
    vector<bool> lazy;  // 懒标记：是否需要翻转

    void maintain(int o) {
        ones[o] = ones[o * 2] + ones[o * 2 + 1];
    }

    void pushDown(int o, int l, int r) {
        if (lazy[o]) {
            int mid = (l + r) / 2;
            // 翻转左子树
            ones[o * 2] = (mid - l + 1) - ones[o * 2];
            lazy[o * 2] = !lazy[o * 2];
            // 翻转右子树
            ones[o * 2 + 1] = (r - mid) - ones[o * 2 + 1];
            lazy[o * 2 + 1] = !lazy[o * 2 + 1];
            lazy[o] = false;
        }
    }

public:
    LazySegementTree(vector<int>& nums) {
        int n = nums.size();
        ones.resize(4 * n);
        lazy.resize(4 * n, false);
        build(1, 0, n - 1, nums);
    }

    void build(int o, int l, int r, vector<int>& nums) {
        if (l == r) {
            ones[o] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(o * 2, l, mid, nums);
        build(o * 2 + 1, mid + 1, r, nums);
        maintain(o);
    }

    void update(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            ones[o] = (r - l + 1) - ones[o]; // 翻转
            lazy[o] = !lazy[o];
            return;
        }
        pushDown(o, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid) update(o * 2, l, mid, ql, qr);
        if (qr > mid) update(o * 2 + 1, mid + 1, r, ql, qr);
        maintain(o);
    }

    int query(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return ones[o];
        }
        pushDown(o, l, r);
        int mid = (l + r) / 2;
        int res = 0;
        if (ql <= mid) res += query(o * 2, l, mid, ql, qr);
        if (qr > mid) res += query(o * 2 + 1, mid + 1, r, ql, qr);
        return res;
    }
};

vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
    int n = nums1.size();
    LazySegementTree tree(nums1);
    long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
    vector<long long> ans;

    for (auto& q : queries) {
        if (q[0] == 1) {
            tree.update(1, 0, n - 1, q[1], q[2]);
        } else if (q[0] == 2) {
            int ones = tree.query(1, 0, n - 1, 0, n - 1);
            sum += 1LL * ones * q[1];
        } else {
            ans.push_back(sum);
        }
    }
    return ans;
}
int main() {
    vector<int> nums1 = {1, 0, 1};
    vector<int> nums2 = {0, 0, 0};
    vector<vector<int>> queries = {
        {1, 1, 1},
        {2, 1, 0},
        {3, 0, 0}
    };
    for (auto& i : handleQuery(nums1, nums2, queries)) {
        cout << i << " ";
    }
    return 0;
}
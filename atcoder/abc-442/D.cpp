#include <bits/stdc++.h>
using namespace std;
#define int long long
class SegmentTree {
private:
    vector<int> mx, lazy;
    int size = 0;
    void maintain(int o) {
        mx[o] = mx[o * 2] + mx[o * 2 + 1];
    }
    void build(int o, int l, int r, vector<int>& nums) {
        if (l == r) {
            mx[o] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(o * 2, l, mid, nums);
        build(o * 2 + 1, mid + 1, r, nums);

        maintain(o);
    }
    void pushDown(int o, int l, int r) {
        if (lazy[o]) {
            int add = lazy[o];
            int mid = (l + r) / 2;
            mx[o * 2] += add * (mid - l + 1);
            mx[o * 2 + 1] += add * (r - mid);
            lazy[o * 2] += add;
            lazy[o * 2 + 1] += add;
            lazy[o] = 0;
        }
    }
public:
    SegmentTree(vector<int>& nums) : size(nums.size()) {
        mx = vector<int>(nums.size() * 4);
        lazy = vector<int>(nums.size() * 4, 0);
        build(1, 0, nums.size() - 1, nums);
    }
    int query(int o, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr) {
            return mx[o];
        }
        pushDown(o, l, r);
        int tmp = 0;
        int mid = (l + r) / 2;
        if (mid >= ql) {
            tmp += query(o * 2, l, mid, ql, qr);
        }
        if (mid + 1 <= qr) {
            tmp += query(o * 2 + 1, mid + 1, r, ql, qr);
        }
        return tmp;
    }
    void update(int o, int l, int r, int ql, int qr, int val) {
        if (l >= ql && r <= qr) {
            lazy[o] += val;
            mx[o] += val * (r - l + 1);
            return;
        }
        pushDown(o, l, r);
        int mid = (l + r) / 2;
        if (mid >= ql) {
            update(o * 2, l, mid, ql, qr, val);
        } 
        if (mid + 1 <= qr) {
            update(o * 2 + 1, mid + 1, r, ql, qr, val);
        }
        maintain(o);
    }
};
signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    SegmentTree st(nums);
    while (q--) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            int x;
            cin >> x;
            int c = nums[x - 1] - nums[x];
            swap(nums[x - 1], nums[x]);
            st.update(1, 0, nums.size() - 1, x - 1, x - 1, -c);
            st.update(1, 0, nums.size() - 1, x, x, c);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(1, 0, nums.size() - 1, l - 1, r - 1) << endl;
        }
    }
    return 0;
}
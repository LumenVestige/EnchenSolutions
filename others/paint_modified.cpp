#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int left_color;      // 左端点颜色
    int right_color;     // 右端点颜色
    int max_len;         // 最长连续长度
    int max_l;           // 最长区间左端点
    int max_r;           // 最长区间右端点
    int left_len;        // 左连续长度
    int right_len;       // 右连续长度
    int lazy;            // 懒标记
    int left;            // 左孩子
    int right;           // 右孩子
    int len;             // 当前区间长度
};

vector<Node> tree;
int cnt;
const int MAX_R = 1e9;

class SegmentTree {
private:
    int root;
    const double MAX_R = 1e9;

    void push_down(int node, int l, int r) {
        if (tree[node].lazy != -1) {
            int mid = (l + r) / 2;
            if (!tree[node].left) {
                tree[node].left = ++cnt;
                tree[cnt] = {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, mid - l};
            }
            if (!tree[node].right) {
                tree[node].right = ++cnt;
                tree[cnt] = {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, r - mid};
            }

            int color = tree[node].lazy;
            Node &left = tree[tree[node].left];
            Node &right = tree[tree[node].right];

            left.left_color = left.right_color = color;
            left.max_len = left.len;
            left.max_l = l;
            left.max_r = mid;
            left.left_len = left.right_len = left.len;
            left.lazy = color;

            right.left_color = right.right_color = color;
            right.max_len = right.len;
            right.max_l = mid;
            right.max_r = r;
            right.left_len = right.right_len = right.len;
            right.lazy = color;

            tree[node].lazy = -1;
        }
    }

    void push_up(int node, int l, int r) {
        int mid = (l + r) / 2;
        Node &left = tree[tree[node].left];
        Node &right = tree[tree[node].right];

        tree[node].left_color = left.left_color;
        tree[node].right_color = right.right_color;

        tree[node].left_len = left.left_len;
        if (left.left_len == left.len && left.right_color == right.left_color) {
            tree[node].left_len += right.left_len;
        }

        tree[node].right_len = right.right_len;
        if (right.right_len == right.len && right.left_color == left.right_color) {
            tree[node].right_len += left.right_len;
        }

        tree[node].max_len = left.max_len;
        tree[node].max_l = left.max_l;
        tree[node].max_r = left.max_r;

        if (right.max_len > tree[node].max_len ||
            (right.max_len == tree[node].max_len && right.max_l < tree[node].max_l)) {
            tree[node].max_len = right.max_len;
            tree[node].max_l = right.max_l;
            tree[node].max_r = right.max_r;
        }

        if (left.right_color == right.left_color) {
            int len = left.right_len + right.left_len;
            if (len > tree[node].max_len ||
                (len == tree[node].max_len && (mid - left.right_len) < tree[node].max_l)) {
                tree[node].max_len = len;
                tree[node].max_l = mid - left.right_len;
                tree[node].max_r = mid + right.left_len;
            }
        }
    }

    void update(int node, int l, int r, int ul, int ur, int color) {
        if (ur <= l || ul >= r) return;
        if (ul <= l && r <= ur) {
            tree[node].left_color = tree[node].right_color = color;
            tree[node].max_len = tree[node].len;
            tree[node].max_l = l;
            tree[node].max_r = r;
            tree[node].left_len = tree[node].right_len = tree[node].len;
            tree[node].lazy = color;
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        if (!tree[node].left) {
            tree[node].left = ++cnt;
            tree[cnt] = {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, mid - l};
        }
        if (!tree[node].right) {
            tree[node].right = ++cnt;
            tree[cnt] = {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, r - mid};
        }
        update(tree[node].left, l, mid, ul, ur, color);
        update(tree[node].right, mid, r, ul, ur, color);
        push_up(node, l, r);
    }

    struct Result {
        int max_len;
        int max_l;
        int max_r;
        int left_color;
        int right_color;
        int left_len;
        int right_len;
        int len;
    };

    Result query(int node, int l, int r, int ql, int qr) {
        if (qr <= l || ql >= r) {
            return {0, -1, -1, -1, -1, 0, 0, 0};
        }
        if (ql <= l && r <= qr) {
            return {tree[node].max_len, tree[node].max_l, tree[node].max_r,
                    tree[node].left_color, tree[node].right_color,
                    tree[node].left_len, tree[node].right_len, tree[node].len};
        }
        push_down(node, l, r);
        int mid = (l + r) / 2;
        if (!tree[node].left) {
            tree[node].left = ++cnt;
            tree[cnt] = {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, mid - l};
        }
        if (!tree[node].right) {
            tree[node].right = ++cnt;
            tree[cnt] = {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, r - mid};
        }

        Result left = query(tree[node].left, l, mid, ql, qr);
        Result right = query(tree[node].right, mid, r, ql, qr);

        if (left.max_len == 0) return right;
        if (right.max_len == 0) return left;

        Result res;
        res.left_color = left.left_color;
        res.right_color = right.right_color;
        res.len = left.len + right.len;

        res.left_len = left.left_len;
        if (left.left_len == left.len && left.right_color == right.left_color) {
            res.left_len += right.left_len;
        }

        res.right_len = right.right_len;
        if (right.right_len == right.len && right.left_color == left.right_color) {
            res.right_len += left.right_len;
        }

        res.max_len = left.max_len;
        res.max_l = left.max_l;
        res.max_r = left.max_r;

        if (right.max_len > res.max_len ||
            (right.max_len == res.max_len && right.max_l < res.max_l)) {
            res.max_len = right.max_len;
            res.max_l = right.max_l;
            res.max_r = right.max_r;
        }

        if (left.right_color == right.left_color) {
            int len = left.right_len + right.left_len;
            int combined_l = mid - left.right_len;
            int combined_r = mid + right.left_len;
            if (len > res.max_len ||
                (len == res.max_len && combined_l < res.max_l)) {
                res.max_len = len;
                res.max_l = combined_l;
                res.max_r = combined_r;
            }
        }

        return res;
    }

public:
    SegmentTree() {
        cnt = 0;
        tree.resize(4000000);
        root = ++cnt;
        tree[root] = {0, 0, MAX_R, 0, MAX_R, MAX_R, MAX_R, 0, 0, 0, MAX_R};
    }

    void update(int l, int r, int color) {
        update(root, 0, MAX_R, l, r, color);
    }

    pair<int, int> query(int l, int r) {
        Result res = query(root, 0, MAX_R, l, r);
        return {res.max_l, res.max_r};
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    SegmentTree st;

    while (m--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r, z;
            cin >> l >> r >> z;
            st.update(l, r, z);
        } else {
            int l, r;
            cin >> l >> r;
            auto ans = st.query(l, r);
            cout << ans.first << " " << ans.second << "\n";
        }
    }

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct Node {
    int left_color, right_color;
    double max_len;
    double max_l, max_r;
    double left_len, right_len;
    int lazy;
    int left, right;
} tree[MAXN * 40];

int cnt = 0;
const double MAX_R = 1e9;

void push_down(int node, double l, double r) {
    if (tree[node].lazy != -1) {
        int mid = (l + r) / 2;
        if (!tree[node].left) tree[node].left = ++cnt;
        if (!tree[node].right) tree[node].right = ++cnt;

        int color = tree[node].lazy;
        Node &left = tree[tree[node].left];
        left.left_color = left.right_color = color;
        left.max_len = mid - l;
        left.max_l = l;
        left.max_r = mid;
        left.left_len = left.right_len = mid - l;
        left.lazy = color;

        Node &right = tree[tree[node].right];
        right.left_color = right.right_color = color;
        right.max_len = r - mid;
        right.max_l = mid;
        right.max_r = r;
        right.left_len = right.right_len = r - mid;
        right.lazy = color;

        tree[node].lazy = -1;
    }
}

void push_up(int node, double l, double r) {
    int mid = (l + r) / 2;
    Node &left = tree[tree[node].left];
    Node &right = tree[tree[node].right];

    tree[node].left_color = left.left_color;
    tree[node].right_color = right.right_color;

    tree[node].left_len = left.left_len;
    if (left.left_len == mid - l && left.right_color == right.left_color) {
        tree[node].left_len += right.left_len;
    }

    tree[node].right_len = right.right_len;
    if (right.right_len == r - mid && right.left_color == left.right_color) {
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
        double len = left.right_len + right.left_len;
        if (len > tree[node].max_len ||
            (len == tree[node].max_len && (mid - left.right_len) < tree[node].max_l)) {
            tree[node].max_len = len;
            tree[node].max_l = mid - left.right_len;
            tree[node].max_r = mid + right.left_len;
        }
    }
}

void update(int node, double l, double r, double ul, double ur, int color) {
    if (ur <= l || ul >= r) return;
    if (ul <= l && r <= ur) {
        tree[node].left_color = tree[node].right_color = color;
        tree[node].max_len = r - l;
        tree[node].max_l = l;
        tree[node].max_r = r;
        tree[node].left_len = tree[node].right_len = r - l;
        tree[node].lazy = color;
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    if (!tree[node].left) tree[node].left = ++cnt;
    if (!tree[node].right) tree[node].right = ++cnt;
    update(tree[node].left, l, mid, ul, ur, color);
    update(tree[node].right, mid, r, ul, ur, color);
    push_up(node, l, r);
}

struct Result {
    double max_len;
    double max_l;
    double max_r;
    int left_color;
    int right_color;
    double left_len;
    double right_len;
    double len;
};

Result query(int node, double l, double r, double ql, double qr) {
    if (qr <= l || ql >= r) {
        return {0, -1, -1, -1, -1, 0, 0, 0};
    }
    if (ql <= l && r <= qr) {
        return {tree[node].max_len, tree[node].max_l, tree[node].max_r,
                tree[node].left_color, tree[node].right_color,
                tree[node].left_len, tree[node].right_len, r - l};
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    if (!tree[node].left) tree[node].left = ++cnt;
    if (!tree[node].right) tree[node].right = ++cnt;

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
        double len = left.right_len + right.left_len;
        double combined_l = mid - left.right_len;
        double combined_r = mid + right.left_len;
        if (len > res.max_len ||
            (len == res.max_len && combined_l < res.max_l)) {
            res.max_len = len;
            res.max_l = combined_l;
            res.max_r = combined_r;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cnt = 1;
    tree[1].left_color = tree[1].right_color = 0;
    tree[1].max_len = MAX_R;
    tree[1].max_l = 0;
    tree[1].max_r = MAX_R;
    tree[1].left_len = tree[1].right_len = MAX_R;
    tree[1].lazy = 0;

    int m;
    cin >> m;
    while (m--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            double l, r;
            int z;
            cin >> l >> r >> z;
            update(1, 0, MAX_R, l, r, z);
        } else {
            double l, r;
            cin >> l >> r;
            Result res = query(1, 0, MAX_R, l, r);
            cout << (int)res.max_l << " " << (int)res.max_r << "\n";
        }
    }

    return 0;
}

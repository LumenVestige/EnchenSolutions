#include <bits/stdc++.h>
using namespace std;

const int MAXM = 100005;
struct Node {
    long long L_end, R_end;
    long long l_col, r_col;
    long long l_l, l_r;
    long long r_l, r_r;
    long long max_l, max_r;
    long long lazy;
};

long long X[MAXM * 2 + 5];
int num_x = 0;

struct Op {
    int opt;
    long long l, r, z;
} ops[MAXM];

int get_idx(long long x) {
    return lower_bound(X + 1, X + 1 + num_x, x) - X;
}

Node tree[MAXM * 8 + 5];

void apply(int u, long long col) {
    tree[u].lazy = col;
    tree[u].l_col = tree[u].r_col = col;
    tree[u].l_l = tree[u].r_l = tree[u].max_l = tree[u].L_end;
    tree[u].l_r = tree[u].r_r = tree[u].max_r = tree[u].R_end;
}

void pushdown(int u) {
    if (tree[u].lazy != -1) {
        apply(u << 1, tree[u].lazy);
        apply(u << 1 | 1, tree[u].lazy);
        tree[u].lazy = -1;
    }
}

Node merge(const Node& lc, const Node& rc) {
    Node u;
    u.L_end = lc.L_end;
    u.R_end = rc.R_end;
    u.lazy = -1;

    u.l_col = lc.l_col;
    u.l_l = lc.l_l;
    if (lc.l_r == lc.R_end && lc.l_col == rc.l_col) {
        u.l_r = rc.l_r;
    } else {
        u.l_r = lc.l_r;
    }

    u.r_col = rc.r_col;
    u.r_r = rc.r_r;
    if (rc.r_l == rc.L_end && rc.r_col == lc.r_col) {
        u.r_l = lc.r_l;
    } else {
        u.r_l = rc.r_l;
    }

    u.max_l = lc.max_l;
    u.max_r = lc.max_r;
    auto update_max = [&](long long l, long long r) {
        long long len = r - l;
        long long cur_len = u.max_r - u.max_l;
        if (len > cur_len) {
            u.max_l = l;
            u.max_r = r;
        } else if (len == cur_len && l < u.max_l) {
            u.max_l = l;
            u.max_r = r;
        }
    };

    update_max(rc.max_l, rc.max_r);
    
    if (lc.r_col == rc.l_col) {
        update_max(lc.r_l, rc.l_r);
    }
    
    return u;
}

void build(int u, int l, int r) {
    tree[u].lazy = -1;
    if (l == r) {
        tree[u].L_end = X[l];
        tree[u].R_end = X[l + 1];
        tree[u].l_col = tree[u].r_col = 0;
        tree[u].l_l = tree[u].r_l = tree[u].max_l = X[l];
        tree[u].l_r = tree[u].r_r = tree[u].max_r = X[l + 1];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
}

void update(int u, int l, int r, int ql, int qr, long long col) {
    if (ql <= l && r <= qr) {
        apply(u, col);
        return;
    }
    pushdown(u);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(u << 1, l, mid, ql, qr, col);
    if (qr > mid) update(u << 1 | 1, mid + 1, r, ql, qr, col);
    tree[u] = merge(tree[u << 1], tree[u << 1 | 1]);
}
Node query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[u];
    pushdown(u);
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(u << 1, l, mid, ql, qr);
    if (ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
    return merge(query(u << 1, l, mid, ql, qr), query(u << 1 | 1, mid + 1, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    if (!(cin >> m)) return 0;

    X[++num_x] = 0;
    X[++num_x] = 1000000000;

    for (int i = 1; i <= m; ++i) {
        cin >> ops[i].opt;
        if (ops[i].opt == 1) {
            cin >> ops[i].l >> ops[i].r >> ops[i].z;
            X[++num_x] = ops[i].l;
            X[++num_x] = ops[i].r;
        } else {
            cin >> ops[i].l >> ops[i].r;
            X[++num_x] = ops[i].l;
            X[++num_x] = ops[i].r;
        }
    }

    sort(X + 1, X + 1 + num_x);
    num_x = unique(X + 1, X + 1 + num_x) - (X + 1);

    int N = num_x - 1; 
    if (N > 0) {
        build(1, 1, N);
    }

    for (int i = 1; i <= m; ++i) {
        if (ops[i].opt == 1) {
            int ql = get_idx(ops[i].l);
            int qr = get_idx(ops[i].r) - 1;
            if (ql <= qr) {
                update(1, 1, N, ql, qr, ops[i].z);
            }
        } else {
            int ql = get_idx(ops[i].l);
            int qr = get_idx(ops[i].r) - 1;
            if (ql <= qr) {
                Node res = query(1, 1, N, ql, qr);
                cout << res.max_l << " " << res.max_r << "\n";
            } else {
                cout << ops[i].l << " " << ops[i].l << "\n";
            }
        }
    }

    return 0;
}
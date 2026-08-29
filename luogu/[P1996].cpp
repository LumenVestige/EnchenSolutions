#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node {
    node* next;
    int val;
    node(int x) : val(x), next(nullptr){}
};
void solve() {
    int n, m;
    cin >> n >> m;
    node* root = new node(-1);
    node* cur = root;
    for (int i = 1; i <= n; ++i) {
        cur->next = new node(i);
        cur = cur->next;
    }
    vector<int> ans;
    cur->next = root->next;
    cur = root->next;
    int cnt = 0;
    while (cur->next->val != cur->val) {
        if (++cnt == m-1) {
            // 删掉下一个
            ans.push_back(cur->next->val);
            cur->next = cur->next->next;
            cnt = 0;
        }
        cur = cur->next;
    }
    ans.push_back(cur->val);
    for (auto& i : ans) {
        cout << i << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
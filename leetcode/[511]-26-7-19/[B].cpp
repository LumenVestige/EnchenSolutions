#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countDominantNodes(TreeNode* root) {
    int ans = 0;
    // 看看r树的最大值是多少
    auto dfs = [&](auto&& dfs, TreeNode* r) -> int {
        if (r == nullptr) {
            return 0;
        }
        // 看左边，看右边
        int left = dfs(dfs, r->left);
        int right = dfs(dfs, r->right);
        if (r->val > left && r-> val > right) {
            ans++;
        }
        return max({r->val, left, right});
    };
    dfs(dfs, root);
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {

    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
int maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    // 层序遍历
    queue<TreeNode*> q;
    q.emplace(root);
    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto t = q.front();
            if (t->left != nullptr)
                q.emplace(t->left);
            if (t->right != nullptr)
                q.emplace(t->right);
            q.pop();
        }
        ans++;
    }
    return ans;
}
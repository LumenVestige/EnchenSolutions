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
 
int minDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    int left = INT_MAX, right = INT_MAX;
    if (root->left != nullptr) {
        left = minDepth(root->left) + 1;
    }
    if (root->right != nullptr) {
        right = minDepth(root->right) + 1;
    }
    return min(left, right);
}
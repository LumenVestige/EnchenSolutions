//
// Created by sanenchen on 25-7-29.
//
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

bool isSameTree(TreeNode *p, TreeNode *q) {
    function<void(vector<int>&, TreeNode*)> dfs = [&](vector<int>& num, TreeNode* root) -> void {
        if (root == nullptr) {
            num.push_back(-1);
            return;
        }

        // 中序遍历
        dfs(num, root->left);
        num.push_back(root->val);
        dfs(num, root->right);
    };
    vector<int> n1;
    dfs(n1, p);

    vector<int> n2;
    dfs(n2, q);
    if (n1.size() != n2.size())
        return false;
    for (int i = 0; i < n1.size(); i++) {
        if (n1[i] != n2[i])
            return false;
    }
    return true;

}

int main() {
    auto *p = new TreeNode(1);
    p->left = (new TreeNode(2));
    p->right = (new TreeNode(3));

    auto *q = new TreeNode(1);
    q->left = (new TreeNode(3));
    q->right = (new TreeNode(2));


    cout << isSameTree(p, q);

    return 0;
}

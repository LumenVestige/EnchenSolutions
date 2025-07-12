//
// Created by sanenchen on 25-7-12.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //BINARY_TREE_H
